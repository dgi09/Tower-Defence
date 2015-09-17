#include "ColdTowerInfoContainer.h"
#include "Label.h"
#include "Container.h"
#include "ColdTower.h"
#include "GUISystem.h"
#include <string>
#include <sstream>
#include <iomanip>


ColdTowerInfoContainer::ColdTowerInfoContainer()
{
	lblAttackRating = nullptr;
	lblDmg = nullptr;
	lblPrice = nullptr;
	lblRange = nullptr;
	lblAmmoSpeed = nullptr;

	font = nullptr;
}

ColdTowerInfoContainer::~ColdTowerInfoContainer()
{
	GUISystem::getPtr()->deleteWidget(lblAttackRating);
	GUISystem::getPtr()->deleteWidget(lblDmg);
	GUISystem::getPtr()->deleteWidget(lblPrice);
	GUISystem::getPtr()->deleteWidget(lblRange);
	GUISystem::getPtr()->deleteWidget(lblAmmoSpeed);
	GUISystem::getPtr()->deleteWidget(lblSpeedDecrease);
	GUISystem::getPtr()->deleteWidget(lblSlowDuration);

	TTF_CloseFont(font);
}

void ColdTowerInfoContainer::init(int price,ColdTower * tower)
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

	lblSlowDuration = GUISystem::getPtr()->createLabel();
	lblSlowDuration->setFont(font);
	lblSlowDuration->setColor(255,255,255);
	lblSlowDuration->setPosition(lblAmmoSpeed->getX(),lblAmmoSpeed->getY() + lblAmmoSpeed->getHeight() + separation);
	lblSlowDuration->setText("Slow Duration : " + std::to_string(tower->getSlowingDuration()) + "ms");
	
	lblSpeedDecrease = GUISystem::getPtr()->createLabel();
	lblSpeedDecrease->setFont(font);
	lblSpeedDecrease->setColor(255,255,255);
	lblSpeedDecrease->setPosition(lblSlowDuration->getX(),lblSlowDuration->getY() + lblSlowDuration->getHeight() + separation);
	lblSpeedDecrease->setText("Speed Decrease : " + std::to_string(tower->getSpeedDecrease()));

}

void ColdTowerInfoContainer::attach(Container * container)
{
	container->addWidget(lblRange);
	container->addWidget(lblPrice);
	container->addWidget(lblDmg);
	container->addWidget(lblAttackRating);
	container->addWidget(lblAmmoSpeed);
	container->addWidget(lblSlowDuration);
	container->addWidget(lblSpeedDecrease);
}
