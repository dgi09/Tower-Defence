#pragma once
#include "IObservee.h"
#include "ShopItem.h"
#include <vector>
#include "Manager.h"

struct PlayerStat
{
	int gold;
};

enum PlayerEvents
{
	HealthChange = 0,
	GoldChange
};

class Player : public IObservee
{
	int health;
	int maxHealth;

	int gold;

public:
	Player(void);
	~Player(void);


	void setHealth(int health);
	int getHealth();

	void setMaxHealth(int health);
	int getMaxHealth();


	void addGold(int gold);
	void reduceGold(int amount);
	void setGold(int gold);
	int getGold();

	void reduceHelth(int reduce);
	void increaseHealth(int increase);
	void healMax();

};

