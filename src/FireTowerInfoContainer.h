#pragma once 

#include <SDL_ttf.h>

class Container;
class Label;
class FireTower;


class FireTowerInfoContainer
{
	Label * lblDmg;
	Label * lblRange;
	Label * lblPrice;
	Label * lblAttackRating;
	Label * lblAmmoSpeed;
	Label * lblDotDamage;
	Label * lblDotDuration;
	Label * lblDotPeriod;

	TTF_Font * font;

public:
	FireTowerInfoContainer();
	~FireTowerInfoContainer();

	void init(int price,FireTower * tower);
	void attach(Container * container);
};