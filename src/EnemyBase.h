#pragma once
#include "Sprite.h"
#include "Damage.h"
#include "Resistance.h"
#include "Effect.h"
#include <vector>
#include "LifeBar.h"

class Road;
class Wave;

class EnemyBase : public Sprite
{
protected:

	LifeBar bar;
	Road * road;
	unsigned int currentRoadTile;
	bool showBar;
	double distance;

	std::vector<Effect*> effects;
	std::vector<Effect*>::iterator effectIt;
	std::vector<Resistance> resistances;

	bool reachedEnd;

private:
	double life;
	double maxLife;
	int speed;

	int gold;

public:

	EnemyBase(void);
	virtual ~EnemyBase(void);
	
	virtual void init();
	virtual void takeDamage(Damage & damage);
	virtual void addEffect(Effect * effect);

	void removeEffect(Effect * effect);
	void removeAllEffects();

	virtual void onDie();

	void setMaxLife(double maxLife);
	double  getMaxLife();

	void setLife(double life);
	double	getLife();
	bool alive();
	bool reachEnd();

	void setSpeed(int speed);
	int getSpeed();

	virtual void draw(SDL_Renderer * renderer);

	virtual void update();


	void setRoad(Road * road);

	void showLifeBar();
	void hideLifeBar();

	virtual void spawn();

	void setGold(int gold);
	int getGold();


	void addResistance(Resistance res);
	double getCoveredDistance();
protected:
	void updateEffects();
	virtual void onAreaChange();

	void givePlayerLoot();

};
