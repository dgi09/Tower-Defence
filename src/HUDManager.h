#pragma once
#include "Manager.h"
#include "HUDElement.h"

class HUDManager : public Manager<HUDElement>
{
public:
	HUDManager(void);
	~HUDManager(void);

	void drawHud(SDL_Renderer * renderer);
};

