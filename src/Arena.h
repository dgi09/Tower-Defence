#pragma once
#include <SDL.h>
#include "Map.h"
#include "DrawableObjectManager.h"
#include "UpdateableObjectManager.h"
#include "WaveInteractorManager.h"
#include "TowerBase.h"
#include "Ammos.h"
#include "ArenaInternalMenager.h"
#include "IObservee.h"


class IArenaObject;
class IClickable;

enum ArenaEvents
{
	PlayerCleansWaves = 10,
};

class Arena : public IObservee
{
	Map map;
	DrawableObjectManager drawableObjects;

	UpdateableObjectManager updateableObjects;
	WaveInteractorManager waveInteractors;
	Manager<IClickable> clickableObjects;
	Manager<Wave> waves;

	ArenaInternalMenager mgr;

	bool finalWaveAdded;

	IClickable * focused;
public:

	Arena(void);
	~Arena(void);

	void drawArena(SDL_Renderer * renderer);
	void updateArena();

	void addArenaObject(IArenaObject * obj);
	void removeArenaObject(IArenaObject * obj);
	
	void addWave(Wave * wave);
	void removeWave(Wave * wave);

	bool getMapTile(int x,int y);

	void loadMapTexture(const char * fileName);
	void loadMapData(const char * fileName);
	void loadRoad(const char * fileName);

	void tryInteract(int x,int y);

	void setFinalWaveAdded(bool v);
	
};

