#pragma once
#include "Damage.h"

class Resistance 
{
public:
	DamageType dmgType;
	double percentige;

	double getReducedDamageValue(double dmgValue);

};