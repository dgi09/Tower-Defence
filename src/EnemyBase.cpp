#include "EnemyBase.h"
#include <iostream>
#include "Map.h"
#include "Wave.h"
#include "GamePlayMediator.h"
#include "TextureLoader.h"
#include "TexturePool.h"

EnemyBase::EnemyBase(void):Sprite()
{
	
}


EnemyBase::~EnemyBase(void)
{
	texture = NULL;
	removeAllEffects();
	road = NULL;
}

void EnemyBase::init()
{
	
	//texture = TexturePool::getPtr()->getTexture("Data/enemy.png",area.w,area.h);
	life = 0;
	bar.setEnemy(this);

	currentRoadTile = 0;
	road = NULL;

	showLifeBar();
	reachedEnd = false;
	distance = 0.0;
	removeAllEffects();
}

void EnemyBase::takeDamage(Damage & damage)
{
	double finalDamage = damage.value;

	for(int i = 0;i < resistances.size();i++)
	{
		if(resistances[i].dmgType = damage.type)
		{
			finalDamage = resistances[i].getReducedDamageValue(damage.value);
			break;
		}
	}

	life -= finalDamage;

	if(life <= 0)
	{
		onDie();
	}
}

void EnemyBase::setMaxLife(double maxLife)
{
	this->maxLife = maxLife;
}

double  EnemyBase::getMaxLife()
{
	return maxLife;
}

void EnemyBase::setLife(double life)
{
	if(life >= maxLife)
		this->life = maxLife;
	else this->life = life;

}

double EnemyBase::getLife()
{
	return life;
}

void EnemyBase::onDie()
{
	//std::cout << "dead";
	givePlayerLoot();
}

bool EnemyBase::alive()
{
	if(life > 0)
		return true;
	else return false;
}

void EnemyBase::setSpeed(int speed)
{
	this->speed = speed;
}

int EnemyBase::getSpeed()
{
	return speed;
}

void EnemyBase::addEffect(Effect * effect)
{
	if(effects.empty())
	{
		effects.push_back(effect);
	}
	else 
	{
		for(effectIt = effects.begin();effectIt != effects.end();++effectIt)
		{
			if((*effectIt)->getID() == effect->getID())
				return;
		}

		effects.push_back(effect);
	}
}

void EnemyBase::removeEffect(Effect * effect)
{
	if(effects.empty() == false)
	for(effectIt = effects.begin();effectIt != effects.end();++effectIt)
	{
		if((*effectIt) == effect)
		{
			delete (*effectIt);
			effects.erase(effectIt);
			break;
		}
	}
}

void EnemyBase::update()
{
	updateEffects();
	bar.centerToPoint(this->getCenterX(),this->getCenterY() - getHeight()/2 - 10);

	if(road != NULL)
	if(currentRoadTile < road->getRoadLenght() - 1)
	{
		SDL_Point nextTile = road->getPointAt(currentRoadTile + 1);
		SDL_Point curTile = road->getPointAt(currentRoadTile);

		int dirX = nextTile.x - curTile.x;
		int dirY = nextTile.y - curTile.y;


		move(dirX * speed,dirY * speed);

		distance += (double)speed;

		double cpX = nextTile.x * TILEWIDTH + TILEWIDTH/2;
		double cpY = nextTile.y * TILEHEIGHT + TILEHEIGHT/2;
		if(dirX != 0)
		{
			if((cpX - getCenterX()) * dirX <= 0)
			{
				 setX(cpX - getWidth()/2);
				 currentRoadTile++;
			}
		}
		else 
		{
			if((cpY - getCenterY())*dirY <= 0)
			{
				
				setY(cpY - getHeight()/2);
				currentRoadTile++;
			}
		}


	}
	else 
	{
		reachedEnd = true;
	}
}

void EnemyBase::updateEffects()
{
	if(effects.empty() == false)
	for(effectIt = effects.begin();effectIt != effects.end();++effectIt)
	{
		if(effects.size() == 0)
			break;
		(*effectIt)->update(this);
	}
}

void EnemyBase::removeAllEffects()
{
	if(effects.empty() == false)
	for(effectIt = effects.begin();effectIt != effects.end();++effectIt)
	{
		if((*effectIt) != NULL)
		{
			delete (*effectIt);
		}
			
	}

	effects.clear();
}

void EnemyBase::draw(SDL_Renderer * renderer)
{
	if(showBar && alive())
	bar.draw(renderer);
	SDL_RenderCopy(renderer,texture,NULL,&area);

}

void EnemyBase::onAreaChange()
{
	
}

void EnemyBase::setRoad(Road * road)
{
	this->road = road;
}

void EnemyBase::showLifeBar()
{
	showBar = true;
}
void EnemyBase::hideLifeBar()
{
	showBar = false;
}

void EnemyBase::spawn()
{
	if(road->getRoadLenght() > 0)
	{
		SDL_Point first = road->getPointAt(0);
		int spX = first.x * TILEWIDTH + TILEWIDTH/2 - getWidth() /2;
		int spY = first.y * TILEHEIGHT + TILEHEIGHT/2 - getHeight() /2;

		setPosition(spX,spY);
	}
}

void EnemyBase::setGold(int gold)
{
	this->gold = gold;
}
int EnemyBase::getGold()
{
	return gold;
}

void EnemyBase::givePlayerLoot()
{
	GamePlayMediator::getPtr()->givePlayerGold(getGold());
}

void EnemyBase::addResistance(Resistance res)
{
	resistances.push_back(res);
}

bool EnemyBase::reachEnd()
{
	return reachedEnd;
}

double EnemyBase::getCoveredDistance()
{
	return distance;
}
