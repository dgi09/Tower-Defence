#include "Arena.h"
#include "TowerBase.h"
#include "Ammo.h"
#include "Wave.h"
#include "EnemyBase.h"
#include "ArenaHeap.h"
#include "GamePlayMediator.h"


Arena::Arena(void)
{
	mgr.init(&drawableObjects,&updateableObjects,&waveInteractors,&clickableObjects);
	finalWaveAdded = false;
	focused = false;
}


Arena::~Arena(void)
{
	drawableObjects.removeAllElements();
	waveInteractors.removeAllElements();
	clickableObjects.removeAllElements();
	updateableObjects.removeAllElements();
}


void Arena::drawArena(SDL_Renderer * renderer)
{
	map.draw(renderer);

	for(int i = 0;i < waves.size();i++)
	{
		waves.getElementByIndex(i)->drawAllEnemies(renderer);
	}

	drawableObjects.drawAll(renderer);

}
void Arena::updateArena()
{
	for(int i = 0;i < waves.size();i++)
	{
		waves.getElementByIndex(i)->updateWave();
		waves.getElementByIndex(i)->updateAllEnemies();
	}


	waveInteractors.interactAll(waves.getArrayPointer(),waves.size());


	updateableObjects.updateAll();

	if(finalWaveAdded && waves.size() == 0)
	{
		notify((int)PlayerCleansWaves);
	}
}


void Arena::addWave(Wave * wave)
{
	for(int i = 0;i<wave->size();i++)
	{
		EnemyBase * enemy = wave->getElementByIndex(i);
		enemy->setRoad(map.getRoadAt(0));
		enemy->spawn();
	}
	waves.addElement(wave);
}

void Arena::removeWave(Wave * wave)
{
	waves.removeElement(wave);
	ArenaHeap::getPtr()->Waves.Delete(wave);
}

bool Arena::getMapTile(int x,int y)
{
	return map.getTileAt(x,y);
}


void Arena::loadMapTexture(const char * fileName)
{
	map.loadMapImage(fileName);
}

void Arena::tryInteract(int x,int y)
{
	bool clickOnArena = true;

	for(int i = 0;i<clickableObjects.size();i++)
	{
		IClickable * current = clickableObjects.getElementByIndex(i);

		if(current->pointInside(x,y))
		{
			clickOnArena = false;
			current->onClick();

			
			if(focused != nullptr && focused != current)
			{
				focused->onOutOfFocus();
				focused = current;
			}
			else 
				focused = current;

		}
	}
	if(clickOnArena)
	{
		if(focused != nullptr) 
			focused->onOutOfFocus();

		focused = nullptr;

		GamePlayMediator::getPtr()->getInfoPanel()->setActiveEmpty();
	}
}

void Arena::loadMapData(const char * fileName)
{
	map.loadMapData(fileName);
}
void Arena::loadRoad(const char * fileName)
{
	map.loadRoadFromFile(fileName);
}

void Arena::addArenaObject(IArenaObject * obj)
{
	obj->onArenaAdd(&mgr);
}

void Arena::removeArenaObject(IArenaObject * obj)
{
	obj->onArenaRemove(&mgr);
}

void Arena::setFinalWaveAdded(bool v)
{
	finalWaveAdded = v;
}



