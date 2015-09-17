#include "SplashCreationTool.h"
#include "GamePlayMediator.h"
#include "Arena.h"
#include "ToolManager.h"
#include "SelectTool.h"
#include "GuiEvent.h"
#include "Map.h"

void SplashCreationTool::onEvent(GuiEvent & evt)
{
	if(evt.type == MOUSE_EVENT)
	{
		if(evt.mouse.type == MOUSE_MOVE)
			range.centerToPoint(evt.mouse.x,evt.mouse.y);

		if(evt.mouse.type == CLICK)
		{

			if(evt.mouse.x <= TILESX * TILEWIDTH && evt.mouse.y <= TILESY * TILEHEIGHT)
			{
				splash->setPosition(evt.mouse.x,evt.mouse.y);
				GamePlayMediator::getPtr()->getArena()->addArenaObject(splash);
				GamePlayMediator::getPtr()->takePlayerGold(cost);
				ToolManager::getPtr()->setActiveTool(new SelectTool());
			}	
		}
	}
}

void SplashCreationTool::drawTool(SDL_Renderer * renderer)
{
	range.draw(renderer);
}

void SplashCreationTool::onPreUse()
{

}

void SplashCreationTool::onPostUse()
{

}

void SplashCreationTool::setSplash(Splash * splash)
{
	this->splash = splash;
	range.setValue(splash->getRange());
	range.setPosition(800,800);

}

SplashCreationTool::SplashCreationTool(void)
{

}

SplashCreationTool::~SplashCreationTool(void)
{

}

void SplashCreationTool::setBombCost(int cost)
{
	this->cost = cost;
}
