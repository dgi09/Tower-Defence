#pragma once

#include "Sprite.h"

class EnemyBase;

class LifeBar : public Sprite
{

	EnemyBase * enemy;
	double maxLife;
	double life;

public:
	LifeBar(void);
	~LifeBar(void);
	void setEnemy(EnemyBase * enemy);
	void draw(SDL_Renderer * renderer);

private:

	void reScale();

};

