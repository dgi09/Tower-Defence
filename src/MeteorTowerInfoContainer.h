#pragma once 

#include <SDL_ttf.h>

class Container;
class Label;
class MeteorTower;


class MeteorTowerInfoContainer
{
	Label * lblSplashDmg;
	Label * lblSplashRange;
	Label * lblTowerRange;
	Label * lblPrice;
	Label * lblAttackRating;
	Label * lblAmmoSpeed;


	TTF_Font * font;

public:
	MeteorTowerInfoContainer();
	~MeteorTowerInfoContainer();

	void init(int price,MeteorTower * tower);
	void attach(Container * container);
};