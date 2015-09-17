#include "GamePlayMediator.h"
#include "DrawableObjectManager.h"
#include "UpdateableObjectManager.h"
#include "WaveInteractorManager.h"


#include "Ammo.h"

#define NULL 0

GamePlayMediator * GamePlayMediator::ptr = NULL;

GamePlayMediator * GamePlayMediator::getPtr()
{
	if(ptr == NULL)
		ptr = new GamePlayMediator;

	return ptr;
}

GamePlayMediator::GamePlayMediator(void)
{

}

GamePlayMediator::~GamePlayMediator(void)
{
	arena = NULL;
}


Arena *  GamePlayMediator::getArena()
{
	return arena;
}


void GamePlayMediator::setArena(Arena * arena)
{
	this->arena = arena;
}

void GamePlayMediator::cleanUp()
{
	if(ptr != NULL)
	{
		delete ptr;
		ptr = NULL;
	}
}

void GamePlayMediator::setPlayer(Player * pl)
{
	this->pl = pl;
}

void GamePlayMediator::givePlayerGold(int gold)
{
	pl->addGold(gold);
}

void GamePlayMediator::takePlayerGold(int gold)
{
	pl->reduceGold(gold);
}

void GamePlayMediator::takePlayerLife(int amount)
{
	pl->reduceHelth(amount);
}

void GamePlayMediator::setInfoPanel(InfoPanel * infoPanel)
{
	ip = infoPanel;
}

InfoPanel * GamePlayMediator::getInfoPanel()
{
	return ip;
}
