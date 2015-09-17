#pragma once


#include "Manager.h"
#include "Arena.h"
#include "Player.h"
#include "ITool.h"
#include "InfoPanel.h"

class GamePlayMediator
{


	static GamePlayMediator * ptr;
	GamePlayMediator();

	Arena * arena;
	Player * pl;
	InfoPanel * ip;
public:
	
	~GamePlayMediator(void);
	static GamePlayMediator * getPtr();
	static void cleanUp();

	void setArena(Arena * arena);
	Arena * getArena();

	void setPlayer(Player * pl);

	void givePlayerGold(int gold);
	void takePlayerGold(int gold);
	void takePlayerLife(int amount);

	void setInfoPanel(InfoPanel * infoPanel);
	InfoPanel * getInfoPanel();

};

