#include "LifeBar.h"
#include "EnemyBase.h"

LifeBar::LifeBar(void):Sprite()
{
	enemy = NULL;
	setHeight(5);
	life = 0.0;
	maxLife = 0.0;
}


LifeBar::~LifeBar(void)
{
	enemy = NULL;
}

void LifeBar::setEnemy(EnemyBase * enemy)
{
	this->enemy = enemy;

}
void LifeBar::draw(SDL_Renderer * renderer)
{
	if(isVisible())
	{
		if(maxLife != enemy->getMaxLife() || life != enemy->getLife())
		{
			reScale();
		}

		SDL_SetRenderDrawColor(renderer,255,0,0,255);
		SDL_RenderFillRect(renderer,&area);
	}
}

void LifeBar::reScale()
{
	
	maxLife = enemy->getMaxLife();
	life = enemy->getLife();

	int w  = enemy->getWidth();
	setWidth(int(life * (w/maxLife)));
}
