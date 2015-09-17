#pragma once

#include "GuiEvent.h"
#include "IDrawable.h"


class ITool
{

public:
	virtual void onEvent(GuiEvent & evt) = 0;
	virtual void drawTool(SDL_Renderer * renderer) = 0;
	virtual void onPreUse() = 0;
	virtual void onPostUse() = 0;
};