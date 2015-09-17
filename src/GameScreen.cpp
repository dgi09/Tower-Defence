#include "GameScreen.h"
#include "Map.h"

#include "PlayerStatHUD.h"
#include "WavesHUD.h"

#include "Player.h"

#include "ToolManager.h"
#include "GUISystem.h"
#include "SelectTool.h"
#include "StoneTowerShopItem.h"
#include "TexturePool.h"
#include "FireTowerShopItem.h"
#include "ArenaHeap.h"
#include "ColdTowerShopItem.h"
#include "SplashCreationTool.h"
#include "BombShopItem.h"
#include "MeteorTowerShopItem.h"
#include <fstream>
#include "LevelsManager.h"
#include "ChooseLevelScreen.h"
#include "ScreenManager.h"

GameScreen::GameScreen(void)
{

}


GameScreen::~GameScreen(void)
{
	
}

void GameScreen::draw(SDL_Renderer * renderer)
{
	arena.drawArena(renderer);
	hudMgr.drawHud(renderer);
	ToolManager::getPtr()->drawTool(renderer);
	GUISystem::getPtr()->drawGUI(renderer);
}

void GameScreen::init(SDL_Window * window)
{
	setRequestAppStop(false);
	ArenaHeap::getPtr()->FireTowers.Allocate(10);
	ArenaHeap::getPtr()->StoneTowers.Allocate(10);
	ArenaHeap::getPtr()->ColdTowers.Allocate(10);
	ArenaHeap::getPtr()->MeteorTowers.Allocate(10);


	ArenaHeap::getPtr()->FireAmmos.Allocate(50);
	ArenaHeap::getPtr()->StoneAmmos.Allocate(50);
	ArenaHeap::getPtr()->ColdAmmos.Allocate(50);
	ArenaHeap::getPtr()->MeteorAmmos.Allocate(50);

	ArenaHeap::getPtr()->Splashes.Allocate(5);

	ArenaHeap::getPtr()->Waves.Allocate(10);
	ArenaHeap::getPtr()->Enemies.Allocate(50);

	GamePlayMediator::getPtr()->setArena(&arena);
	GamePlayMediator::getPtr()->setPlayer(&pl);

	std::string mapDataLoc = folder + "/mapData.txt";
	arena.loadMapData(mapDataLoc.c_str());
	std::string mapTextureLoc = folder + "/map.bmp";
	arena.loadMapTexture(mapTextureLoc.c_str());

	std::string raodLoc = folder + "/roadData.txt";
	arena.loadRoad(raodLoc.c_str());
	arena.addObserver(this);
	
	SelectTool * tool = new SelectTool();
	
	ToolManager::getPtr()->setActiveTool(tool);
	
	waveMgr.loadFromFile(folder + "/waves.txt");

	PlayerStatHUD * hud = new PlayerStatHUD();
	hud->init();
	hud->setPosition(0,0);

	hud->setPlayer(&pl);

	pl.addObserver(hud);
	pl.addObserver(&shop);

	WavesHUD * wavesHud = new WavesHUD();
	wavesHud->init();
	wavesHud->setPosition(0.0,30.0);
	wavesHud->setWavesManager(&waveMgr);

	waveMgr.addObserver(wavesHud);

	hudMgr.addElement(hud);
	hudMgr.addElement(wavesHud);



	shop.init();
	infoPanel.init();

	GamePlayMediator::getPtr()->setInfoPanel(&infoPanel);

	menu.init();
	
	
	
	shop.setPlayer(&pl);

	std::string entry = folder + "/entry.txt";
	initEnttyPoint(entry.c_str());

	shop.updateShopItemsState();

	menu.addMenuElement(&shop);
	menu.addMenuElement(&infoPanel);

	GUISystem::getPtr()->setGUISheet(menu.GetContainer());

	lastMouseState = SDL_MOUSEBUTTONUP;
}

void GameScreen::onEvent(SDL_Event & evt)
{
	GUISystem::getPtr()->injectSDLEvent(evt);

	if(evt.type == SDL_MOUSEBUTTONDOWN)
	{
		ev.type = MOUSE_EVENT;
		ev.mouse.type = CLICK;
		ev.mouse.button = LEFT;

		lastMouseState = SDL_MOUSEBUTTONDOWN;
	}


	if(evt.type == SDL_MOUSEBUTTONUP)
	{
		if(lastMouseState == SDL_MOUSEBUTTONDOWN)
		{
			ev.type = MOUSE_EVENT;
			ev.mouse.type = CLICK;
			ev.mouse.button = LEFT;

			ToolManager::getPtr()->onEvent(ev);

		}
		
		lastMouseState = SDL_MOUSEBUTTONUP;
	}
	
	if(evt.type == SDL_MOUSEMOTION)
	{
		ev.type = MOUSE_EVENT;
		ev.mouse.type = MOUSE_MOVE;
		ev.mouse.x = evt.button.x;
		ev.mouse.y = evt.button.y;
		ToolManager::getPtr()->onEvent(ev);
	}


}

void GameScreen::update()
{
	waveMgr.update();
	arena.updateArena();
}

void GameScreen::onClose()
{
	ArenaHeap::destroy();


	hudMgr.deleteAllElements();
	GamePlayMediator::cleanUp();

	TexturePool::getPtr()->clear();

}
void GameScreen::onPause()
{

}
void GameScreen::onRestart()
{

}

void GameScreen::initEnttyPoint(const char * fileName)
{
	using namespace std;

	fstream file(fileName);

	int iVal;
	double dVal;

	file >> iVal; // life 
	pl.setMaxHealth(iVal);
	pl.setHealth(iVal);
	
	file >> iVal; // gold
	pl.setGold(iVal);

	int numOfitems;
	file >> numOfitems;

	string sVal;

	for(int i = 0;i < numOfitems;i++)
	{
		file >> sVal;
		file >> iVal;

		if(sVal == "stoneTower")
		{
			StoneTowerShopItem * item = new StoneTowerShopItem();
			shop.itemPreInit(item);
			item->init();
			

			item->setItemCost(iVal);

			file >> dVal;
			item->setDamage(dVal);

			file >> dVal;
			item->setRange(dVal);

			file >> iVal;
			item->setAmmoSpeed(iVal);

			file >> iVal;
			item->setShootRate(iVal);

			item->postPropertySet();
			shop.addShopItem(item);
		}
		else if(sVal == "meteorTower")
		{
			
			MeteorTowerShopItem * item = new MeteorTowerShopItem();
			shop.itemPreInit(item);
			item->init();


			item->setItemCost(iVal);

			file >> dVal;
			item->setSplashDamage(dVal);

			file >> iVal;
			item->setSplashRange(iVal);

			file >> dVal;
			item->setTowerRange(dVal);

			file >> iVal;
			item->setAmmoSpeed(iVal);

			file >> iVal;
			item->setShootRate(iVal);

			item->postPropertySet();
			shop.addShopItem(item);
		}
		else if(sVal == "fireTower")
		{
			FireTowerShopItem * item = new FireTowerShopItem();
			
			shop.itemPreInit(item);
			item->init();


			item->setItemCost(iVal);

			file >> dVal;
			item->setDamage(dVal);

			file >> dVal;
			item->setRange(dVal);

			file >> iVal;
			item->setAmmoSpeed(iVal);

			file >> iVal;
			item->setShootRate(iVal);

			file >> dVal;
			item->setDOTDamage(dVal);

			file >> iVal;
			item->setDOTDuration(iVal);

			file >> iVal;
			item->setDOTPeriod(iVal);

			item->postPropertySet();
			shop.addShopItem(item);
		}
		else if(sVal == "coldTower")
		{
			ColdTowerShopItem * item  = new ColdTowerShopItem();
			
			shop.itemPreInit(item);
			item->init();

			item->setItemCost(iVal);

			file >> dVal;
			item->setDamage(dVal);

			file >> dVal;
			item->setRange(dVal);

			file >> iVal;
			item->setAmmoSpeed(iVal);

			file >> iVal;
			item->setShootRate(iVal);

			file >> iVal;
			item->setSlowDuration(iVal);

			file >> iVal;
			item->setSpeedDecrease(iVal);

			item->postPropertySet();
			shop.addShopItem(item);

		}
		else if(sVal == "bomb")
		{
			BombShopItem * item = new BombShopItem();
			
			shop.itemPreInit(item);
			item->init();

			item->setItemCost(iVal);

			file >> dVal;
			item->setDamage(dVal);

			file >> iVal;
			item->setRange(iVal);

			item->postPropertySet();
			shop.addShopItem(item);
		}
	}

	file.close();
}

void GameScreen::setFolder(std::string folder)
{
	this->folder = folder;
}

void GameScreen::observeeChange(int type)
{
	if(type == (int)PlayerCleansWaves)
	{
		LevelsManager::getPtr()->getLevelAt(levelId).wonPoints = 3;

		ChooseLevelScreen * cls = new ChooseLevelScreen();
		ScreenManager::getPtr()->setActiveScreen(cls);

	}
}

void GameScreen::setLevelId(unsigned int id)
{
	levelId = id;
}

