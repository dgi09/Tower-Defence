#pragma once

#include "IScreen.h"
#include "TowerBase.h"
#include "DrawableObjectManager.h"
#include "UpdateableObjectManager.h"
#include "GamePlayMediator.h"
#include "EnemyBase.h"
#include "Wave.h"
#include "WaveInteractorManager.h"
#include "SDL_ttf.h"
#include "TextSprite.h"
#include "HUDManager.h"

#include "Player.h"

#include "TowerCreationTool.h"
#include "Shop.h"
#include "Menu.h"
#include "Splash.h"
#include "WaveManager.h"
#include <string>
#include "IObserver.h"
#include "InfoPanel.h"

class GameScreen : public IScreen , public IObserver
{
	
	Arena arena;
	

	HUDManager hudMgr;
	Player pl;

	bool keys[255];

	GuiEvent ev;

	ITool * tool;

	Shop shop;
	InfoPanel infoPanel;

	Menu menu;

	Uint32 lastMouseState;

	WaveManager waveMgr;

	std::string folder;
	unsigned int levelId;
public:

	GameScreen(void);
	~GameScreen(void);

	void draw(SDL_Renderer * renderer);
	void init(SDL_Window * window);
	void onEvent(SDL_Event & evt);
	void update();
	void onClose();
	void onPause();
	void onRestart();

	void setFolder(std::string folder);
	void setLevelId(unsigned int id);
protected:

	void initEnttyPoint(const char * fileName);

	void observeeChange(int type);

};

