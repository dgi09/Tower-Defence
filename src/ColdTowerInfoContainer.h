#pragma once 

#include <SDL_ttf.h>

class Container;
class Label;
class ColdTower;


class ColdTowerInfoContainer
{
	Label * lblDmg;
	Label * lblRange;
	Label * lblPrice;
	Label * lblAttackRating;
	Label * lblAmmoSpeed;
	Label * lblSlowDuration;
	Label * lblSpeedDecrease;

	TTF_Font * font;

public:
	ColdTowerInfoContainer();
	~ColdTowerInfoContainer();

	void init(int price,ColdTower * tower);
	void attach(Container * container);
};