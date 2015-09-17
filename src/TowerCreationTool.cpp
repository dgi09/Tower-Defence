#include "TowerCreationTool.h"
#include "Arena.h"
#include "GamePlayMediator.h"
#include "Map.h"
#include "ToolManager.h"
#include "SelectTool.h"

TowerCreationTool::TowerCreationTool(void)
{
	placementPossible = false;
	tower = NULL;
	tip.setHeight(TILEHEIGHT);
	tip.setWidth(TILEWIDTH);
	tip.setRed();
	active = false;
}


TowerCreationTool::~TowerCreationTool(void)
{
	tower = NULL;
}

void TowerCreationTool::setTower(TowerBase * tower)
{
	this->tower = tower;
	range.setValue(tower->getRangeValue());
}

void TowerCreationTool::onEvent(GuiEvent  & evt)
{
	if(evt.type == MOUSE_EVENT)
	{
		Arena * arena = GamePlayMediator::getPtr()->getArena();
		int locX = evt.mouse.x / TILEWIDTH;
		int locY = evt.mouse.y  / TILEWIDTH;

		if(locX < TILESX && locY < TILESY)
			active = true;
		else active = false;

		if(evt.mouse.type == MOUSE_MOVE)
		{
			tip.setPosition(locX * TILEWIDTH,locY * TILEHEIGHT);
			range.centerToPoint(locX * TILEWIDTH + TILEWIDTH/2,
								locY * TILEHEIGHT + TILEHEIGHT/2);
			if(arena->getMapTile(locX,locY))
			{
				tip.setGreen();
				placementPossible = true;
			}
			else 
			{
				tip.setRed();
				placementPossible = false;
			}
		}

		if(evt.mouse.type == CLICK)
		{
			if(placementPossible)
			{
				tower->centerToPoint(locX * TILEWIDTH + TILEWIDTH/2,
									locY * TILEHEIGHT + TILEHEIGHT/2);
				tower->showRange(false);
				arena->addArenaObject(tower->copy());
				GamePlayMediator::getPtr()->takePlayerGold(towerCost);
				ToolManager::getPtr()->setActiveTool(new SelectTool());
			}
		}

	}

}

void TowerCreationTool::drawTool(SDL_Renderer * renderer)
{
	if(active)
	{
		tip.draw(renderer);
		range.draw(renderer);
	}
}


void TowerCreationTool::onPreUse()
{
	SDL_ShowCursor(1);
}

void TowerCreationTool::onPostUse()
{
	SDL_ShowCursor(0);
}

void TowerCreationTool::setTowerCost(int gold)
{
	this->towerCost = gold;
}
