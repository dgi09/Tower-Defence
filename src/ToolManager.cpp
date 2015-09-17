#include "ToolManager.h"

ToolManager * ToolManager::ptr = NULL;
ToolManager * ToolManager::getPtr()
{
	if(ptr == NULL)
		ptr = new ToolManager;

	return ptr;
}
ToolManager::ToolManager(void)
{
	activeTool = NULL;
}


ToolManager::~ToolManager(void)
{
	if(activeTool != NULL)
		delete activeTool;
}

void ToolManager::cleanUp()
{
	if(ptr != NULL)
		delete ptr;
}

void ToolManager::setActiveTool(ITool * tool)
{
	if(activeTool != NULL)
	{
		activeTool->onPostUse();
		delete activeTool;
	}

	activeTool = tool;
	activeTool->onPreUse();
}
	
void ToolManager::onEvent(GuiEvent & evt)
{
	if(activeTool != NULL)
	activeTool->onEvent(evt);
}
void ToolManager::drawTool(SDL_Renderer * renderer)
{
	if(activeTool != NULL)
	activeTool->drawTool(renderer);
}

