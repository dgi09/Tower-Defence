#pragma once
#include "ITool.h"
class SelectTool : public ITool
{
public:
	SelectTool(void);
	~SelectTool(void);

	void onEvent(GuiEvent & evt);
	void drawTool(SDL_Renderer * renderer);

	virtual void onPreUse();
	virtual void onPostUse();
};

