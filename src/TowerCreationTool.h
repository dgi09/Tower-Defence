#pragma once
#include "ITool.h"
#include "TowerBase.h"
#include "TowerToolTip.h"
#include "Range.h"


class TowerCreationTool : public ITool
{
	TowerBase * tower;
	TowerToolTip  tip;
	Range range;

	bool placementPossible;
	bool active;

	int towerCost;
public:
	TowerCreationTool(void);
	~TowerCreationTool(void);

	void onEvent(GuiEvent  & evt);
	void drawTool(SDL_Renderer * renderer);

	void setTower(TowerBase * tower);
	void setTowerCost(int gold);

	virtual void onPreUse();
	virtual void onPostUse();

};

