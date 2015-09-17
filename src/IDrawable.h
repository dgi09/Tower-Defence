#pragma once
#include <SDL.h>

class IDrawable
{
public:
	virtual void draw(SDL_Renderer * renderer) = 0;
};

