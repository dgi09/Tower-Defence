#include "Resistance.h"

double Resistance::getReducedDamageValue(double dmgValue)
{
	double portion = dmgValue/100;
	return dmgValue - (percentige * portion);
}