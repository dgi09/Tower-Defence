#include "FireTowerInfoContainer.h"
#include "Label.h"
#include "Container.h"
#include "FireTower.h"
#include "GUISystem.h"
#include <string>
#include <sstream>
#include <iomanip>


FireTowerInfoContainer::FireTowerInfoContainer()
{
	lblAttackRating = nullptr;
	lblDmg = nullptr;
	lblPrice = nullptr;
	lblRange = nullptr;
	lblAmmoSpeed = nullptr;
	lblDotDamage = nullptr;
	lblDotDuration = nullptr;
	lblDotPeriod = nullptr;

	font = nullptr;
}

FireTowerInfoContainer::~FireTowerInfoContainer()
{
	GUISystem::getPtr()->deleteWidget(lblAttackRating);
	GUISystem::getPtr()->deleteWidget(lblDmg);
	GUISystem::getPtr()->deleteWidget(lblPrice);
	GUISystem::getPtr()->deleteWidget(lblRange);
	GUISystem::getPtr()->deleteWidget(lblAmmoSpeed);
	GUISystem::getPtr()->deleteWidget(lblDotDamage);
	GUISystem::getPtr()->deleteWidget(lblDotDuration);
	GUISystem::getPtr()->deleteWidget(lblDotPeriod);

	TTF_CloseFont(font);
}

void FireTowerInfoContainer::init(int price,FireTower * tower)
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

	lblDotDamage = GUISystem::getPtr()->createLabel();
	lblDotDamage->setFont(font);
	lblDotDamage->setColor(255,255,255);
	lblDotDamage->setPosition(lblAmmoSpeed->getX(),lblAmmoSpeed->getY() + lblAmmoSpeed->getHeight() + separation);
	
	str.str("");
	str << std::setprecision(8) << tower->getDOTDamage();
	
	lblDotDamage->setText("DOT Dmg : " + str.str());

	lblDotDuration = GUISystem::getPtr()->createLabel();
	lblDotDuration->setFont(font);
	lblDotDuration->setColor(255,255,255);
	lblDotDuration->setPosition(lblDotDamage->getX(),lblDotDamage->getY() + lblDotDamage->getHeight() + separation);
	lblDotDuration->setText("DOT Duration : " + std::to_string(tower->getDOTDuration()) + "ms");

	lblDotPeriod = GUISystem::getPtr()->createLabel();
	lblDotPeriod->setFont(font);
	lblDotPeriod->setColor(255,255,255);
	lblDotPeriod->setPosition(lblDotDuration->getX(),lblDotDuration->getY() + lblDotDuration->getHeight() + separation);
	lblDotPeriod->setText("DOT Period : " + std::to_string(tower->getDOTPeriod()) + "ms");
}

void FireTowerInfoContainer::attach(Container * container)
{
	container->addWidget(lblRange);
	container->addWidget(lblPrice);
	container->addWidget(lblDmg);
	container->addWidget(lblAttackRating);
	container->addWidget(lblAmmoSpeed);
	container->addWidget(lblDotDamage);
	container->addWidget(lblDotDuration);
	container->addWidget(lblDotPeriod);
}
