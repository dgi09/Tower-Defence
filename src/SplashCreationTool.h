#pragma once
#include "ITool.h"
#include "Range.h"
#include "Splash.h"

class SplashCreationTool : public ITool
{
	Range range;
	Splash * splash;

	int cost;
public:
	SplashCreationTool(void);
	~SplashCreationTool(void);

	virtual void onEvent(GuiEvent & evt);

	virtual void drawTool(SDL_Renderer * renderer);

	virtual void onPreUse();

	virtual void onPostUse();

	void setSplash(Splash * splash);

	void setBombCost(int cost);
};

