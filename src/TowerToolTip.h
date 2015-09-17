#pragma once
#include "Sprite.h"

class TowerToolTip : public Sprite
{
	SDL_Color color;
public:
	TowerToolTip(void);
	~TowerToolTip(void);

	void draw(SDL_Renderer * renderer);

	void setRed();
	void setGreen();
};

