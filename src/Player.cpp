#include "Player.h"


Player::Player(void)
{

}


Player::~Player(void)
{
}


void Player::setHealth(int health)
{
	this->health = health;

	if(this->health > maxHealth)
		this->health = maxHealth;

	if(this->health < 0)
		this->health = 0;

	notify((int)HealthChange);
}
int Player::getHealth()
{
	return health;
}



void Player::setMaxHealth(int health)
{
	this->maxHealth = health;
}

int Player::getMaxHealth()
{
	return maxHealth;
}


void Player::addGold(int gold)
{
	setGold(getGold() + gold);
}

void Player::setGold(int gold)
{
	this->gold = gold;
	notify((int)GoldChange);
}

void Player::reduceHelth(int reduce)
{
	setHealth(getHealth() - reduce);
}

void Player::increaseHealth(int increase)
{
	setHealth(getHealth() + increase);
}

void Player::healMax()
{
	setHealth(getMaxHealth());
}


int Player::getGold()
{
	return gold;
}

void Player::reduceGold(int amount)
{
	setGold(getGold() - amount);
}
