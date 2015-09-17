#pragma once 

enum DamageType
{
	PHISICAL,
	FIRE,
	COLD

};

class Damage
{
public:
	DamageType type;
	double value;
};