#pragma once 

class EnemyBase;

class Effect
{
protected:
	unsigned int iD;
public:
	Effect();
	virtual void update(EnemyBase * enemy) = 0;
	unsigned int getID();
};