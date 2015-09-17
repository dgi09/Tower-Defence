#pragma once 

class Wave;

class IWaveInteractor
{
public:
	virtual void wavesInteract(Wave ** wave,int size) = 0;
};