#pragma once 

#include <SDL_ttf.h>

class Container;
class Label;
class Splash;


class BombInfoContainer
{
	Label * lblDmg;
	Label * lblRange;
	Label * lblPrice;

	TTF_Font * font;

public:
	BombInfoContainer();
	~BombInfoContainer();

	void init(int price,Splash * splash);
	void attach(Container * container);
};