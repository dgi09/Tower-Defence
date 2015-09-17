#pragma once 

#include <SDL_ttf.h>

class Container;
class Label;
class StoneTower;


class StoneTowerInfoContainer
{
	Label * lblDmg;
	Label * lblRange;
	Label * lblPrice;
	Label * lblAttackRating;
	Label * lblAmmoSpeed;
	

	TTF_Font * font;

public:
	StoneTowerInfoContainer();
	~StoneTowerInfoContainer();

	void init(int price,StoneTower * tower);
	void attach(Container * container);
};