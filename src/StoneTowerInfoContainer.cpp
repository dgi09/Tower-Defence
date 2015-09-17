#include "StoneTowerInfoContainer.h"
#include "Label.h"
#include "Container.h"
#include "StoneTower.h"
#include "GUISystem.h"
#include <string>
#include <sstream>
#include <iomanip>


StoneTowerInfoContainer::StoneTowerInfoContainer()
{
	lblAttackRating = nullptr;
	lblDmg = nullptr;
	lblPrice = nullptr;
	lblRange = nullptr;
	lblAmmoSpeed = nullptr;

	font = nullptr;
}

StoneTowerInfoContainer::~StoneTowerInfoContainer()
{
	GUISystem::getPtr()->deleteWidget(lblAttackRating);
	GUISystem::getPtr()->deleteWidget(lblDmg);
	GUISystem::getPtr()->deleteWidget(lblPrice);
	GUISystem::getPtr()->deleteWidget(lblRange);
	GUISystem::getPtr()->deleteWidget(lblAmmoSpeed);

	TTF_CloseFont(font);
}

void StoneTowerInfoContainer::init(int price,StoneTower * tower)
{
	font = TTF_OpenFont("aparaj.ttf",19);

	int separation = 3;

	lblPrice = GUISystem::getPtr()->createLabel();
	lblPrice->setFont(font);
	lblPrice->setColor(255,255,255);
	lblPrice->setPosition(0,0);
	lblPrice->setText("Price : " + std::to_string(price) + " gold");

	std::ostringstream str;
	str << std::setprecision(8) << tower->getDamageValue();

	lblDmg = GUISystem::getPtr()->createLabel();
	lblDmg->setFont(font);
	lblDmg->setColor(255,255,255);
	lblDmg->setPosition(lblPrice->getX(),lblPrice->getHeight() + separation);
	lblDmg->setText("Dmg : " + str.str());
	
	str.str("");
	str << std::setprecision(8);
	str << tower->getRangeValue();

	lblRange = GUISystem::getPtr()->createLabel();
	lblRange->setFont(font);
	lblRange->setColor(255,255,255);
	lblRange->setPosition(lblDmg->getX(),lblDmg->getY() + lblDmg->getHeight() + separation);
	lblRange->setText("Range : " + str.str());

	lblAttackRating = GUISystem::getPtr()->createLabel();
	lblAttackRating->setFont(font);
	lblAttackRating->setColor(255,255,255);
	lblAttackRating->setPosition(lblRange->getX(),lblRange->getY() + lblRange->getHeight() + separation);
	lblAttackRating->setText("Att Rate : " + std::to_string(tower->getShootRate()) + " ms");

	lblAmmoSpeed = GUISystem::getPtr()->createLabel();
	lblAmmoSpeed->setFont(font);
	lblAmmoSpeed->setColor(255,255,255);
	lblAmmoSpeed->setPosition(lblAttackRating->getX(),lblAttackRating->getY() + lblAttackRating->getHeight() + separation);
	lblAmmoSpeed->setText("Ammo Speed : " + std::to_string(tower->getAmmoSpeed()));
}

void StoneTowerInfoContainer::attach(Container * container)
{
	container->addWidget(lblRange);
	container->addWidget(lblPrice);
	container->addWidget(lblDmg);
	container->addWidget(lblAttackRating);
	container->addWidget(lblAmmoSpeed);
}
