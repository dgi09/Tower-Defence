#pragma once
#include "ITool.h"


class ToolManager
{
	ITool * activeTool;

	static ToolManager * ptr;
	ToolManager(void);
public:

	~ToolManager(void);

	static ToolManager * getPtr();
	static void cleanUp();

	void setActiveTool(ITool * tool);
	
	void onEvent(GuiEvent & evt);
	void drawTool(SDL_Renderer * renderer);
};

