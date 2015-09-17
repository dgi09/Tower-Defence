#include "SelectTool.h"
#include "Arena.h"
#include "GamePlayMediator.h"


SelectTool::SelectTool(void)
{
	SDL_ShowCursor(true);
}


SelectTool::~SelectTool(void)
{
}

void SelectTool::onEvent(GuiEvent & evt)
{
	if(evt.type == MOUSE_EVENT)
	{
		if(evt.mouse.type == CLICK)
		{
			Arena * arena = GamePlayMediator::getPtr()->getArena();
			arena->tryInteract(evt.mouse.x,evt.mouse.y);
		}

	}
}
void SelectTool::drawTool(SDL_Renderer * renderer)
{

}

void SelectTool::onPreUse()
{
	SDL_ShowCursor(1);
}

void SelectTool::onPostUse()
{

}