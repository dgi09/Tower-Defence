#pragma once
#include "Manager.h"
#include "IDrawable.h"

class DrawableObjectManager : public Manager<IDrawable>
{
public:
	DrawableObjectManager(void);
	~DrawableObjectManager(void);

	void drawAll(SDL_Renderer * renderer);
};

