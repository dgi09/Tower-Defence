#include "MeteorTowerInfoContainer.h"
#include "Label.h"
#include "Container.h"
#include "MeteorTower.h"
#include "GUISystem.h"
#include <string>
#include <sstream>
#include <iomanip>


MeteorTowerInfoContainer::MeteorTowerInfoContainer()
{
	lblAttackRating = nullptr;
	lblSplashDmg = nullptr;
	lblPrice = nullptr;
	lblSplashRange = nullptr;
	lblAmmoSpeed = nullptr;
	lblTowerRange = nullptr;

	font = nullptr;
}

MeteorTowerInfoContainer::~MeteorTowerInfoContainer()
{
	GUISystem::getPtr()->deleteWidget(lblAttackRating);
	GUISystem::getPtr()->deleteWidget(lblSplashDmg);
	GUISystem::getPtr()->deleteWidget(lblPrice);
	GUISystem::getPtr()->deleteWidget(lblSplashRange);
	GUISystem::getPtr()->deleteWidget(lblAmmoSpeed);
	GUISystem::getPtr()->deleteWidget(lblTowerRange);

	TTF_CloseFont(font);
}

void MeteorTowerInfoContainer::init(int price,MeteorTower * tower)
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

	lblSplashDmg = GUISystem::getPtr()->createLabel();
	lblSplashDmg->setFont(font);
	lblSplashDmg->setColor(255,255,255);
	lblSplashDmg->setPosition(lblPrice->getX(),lblPrice->getHeight() + separation);
	lblSplashDmg->setText("Splash Dmg : " + str.str());

	str.str("");
	str << std::setprecision(8);
	str << tower->getSplashRange();

	lblSplashRange = GUISystem::getPtr()->createLabel();
	lblSplashRange->setFont(font);
	lblSplashRange->setColor(255,255,255);
	lblSplashRange->setPosition(lblSplashDmg->getX(),lblSplashDmg->getY() + lblSplashDmg->getHeight() + separation);
	lblSplashRange->setText("Splash Range : " + str.str());

	str.str("");
	str << std::setprecision(8);
	str << tower->getRangeValue();

	lblTowerRange = GUISystem::getPtr()->createLabel();
	lblTowerRange->setFont(font);
	lblTowerRange->setColor(255,255,255);
	lblTowerRange->setPosition(lblSplashRange->getX(),lblSplashRange->getY() + lblSplashRange->getHeight() + separation);
	lblTowerRange->setText("Tower Range : " + str.str());

	lblAttackRating = GUISystem::getPtr()->createLabel();
	lblAttackRating->setFont(font);
	lblAttackRating->setColor(255,255,255);
	lblAttackRating->setPosition(lblTowerRange->getX(),lblTowerRange->getY() + lblTowerRange->getHeight() + separation);
	lblAttackRating->setText("Att Rate : " + std::to_string(tower->getShootRate()) + " ms");

	lblAmmoSpeed = GUISystem::getPtr()->createLabel();
	lblAmmoSpeed->setFont(font);
	lblAmmoSpeed->setColor(255,255,255);
	lblAmmoSpeed->setPosition(lblAttackRating->getX(),lblAttackRating->getY() + lblAttackRating->getHeight() + separation);
	lblAmmoSpeed->setText("Ammo Speed : " + std::to_string(tower->getAmmoSpeed()));
}

void MeteorTowerInfoContainer::attach(Container * container)
{
	container->addWidget(lblSplashRange);
	container->addWidget(lblPrice);
	container->addWidget(lblSplashDmg);
	container->addWidget(lblAttackRating);
	container->addWidget(lblAmmoSpeed);
	container->addWidget(lblTowerRange);
}
