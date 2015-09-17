#pragma once
#include "Sprite.h"


class HUDElement : public Sprite
{

public:
	HUDElement(void);
	virtual ~HUDElement(void);

	virtual void init() = 0;
	virtual void draw(SDL_Renderer * renderer) = 0;
};

