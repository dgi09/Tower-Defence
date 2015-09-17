#include "BombInfoContainer.h"
#include "Label.h"
#include "Container.h"
#include "Splash.h"
#include "GUISystem.h"
#include <string>
#include <sstream>
#include <iomanip>


BombInfoContainer::BombInfoContainer()
{
	
	lblDmg = nullptr;
	lblPrice = nullptr;
	lblRange = nullptr;

	font = nullptr;
}

BombInfoContainer::~BombInfoContainer()
{
	GUISystem::getPtr()->deleteWidget(lblDmg);
	GUISystem::getPtr()->deleteWidget(lblPrice);
	GUISystem::getPtr()->deleteWidget(lblRange);


	TTF_CloseFont(font);
}

void BombInfoContainer::init(int price,Splash * splash)
{
	font = TTF_OpenFont("aparaj.ttf",19);

	int separation = 3;

	lblPrice = GUISystem::getPtr()->createLabel();
	lblPrice->setFont(font);
	lblPrice->setColor(255,255,255);
	lblPrice->setPosition(0,0);
	lblPrice->setText("Price : " + std::to_string(price) + " gold");

	std::ostringstream str;
	str << std::setprecision(8) << splash->getDamageValue();

	lblDmg = GUISystem::getPtr()->createLabel();
	lblDmg->setFont(font);
	lblDmg->setColor(255,255,255);
	lblDmg->setPosition(lblPrice->getX(),lblPrice->getHeight() + separation);
	lblDmg->setText("Dmg : " + str.str());

	str.str("");
	str << std::setprecision(8);
	str << splash->getRange();

	lblRange = GUISystem::getPtr()->createLabel();
	lblRange->setFont(font);
	lblRange->setColor(255,255,255);
	lblRange->setPosition(lblDmg->getX(),lblDmg->getY() + lblDmg->getHeight() + separation);
	lblRange->setText("Range : " + str.str());

}

void BombInfoContainer::attach(Container * container)
{
	container->addWidget(lblRange);
	container->addWidget(lblPrice);
	container->addWidget(lblDmg);

}
