#pragma once
#include "Pool.h"
#include "Wave.h"
#include "Ammos.h"
#include "Towers.h"
#include "Splash.h"
#include "EnemyBase.h"


class ArenaHeap
{
	static ArenaHeap * ptr;
public:
	static ArenaHeap * getPtr();
	static void destroy();

	Pool<Wave> Waves;
	Pool<EnemyBase> Enemies;

	Pool<FireTower> FireTowers;
	Pool<StoneTower> StoneTowers;
	Pool<ColdTower> ColdTowers;

	Pool<FireAmmo> FireAmmos;
	Pool<StoneAmmo> StoneAmmos;
	Pool<ColdAmmo> ColdAmmos;
	Pool<Splash> Splashes;
	Pool<MeteorAmmo> MeteorAmmos;
	Pool<MeteorTower> MeteorTowers;
};

