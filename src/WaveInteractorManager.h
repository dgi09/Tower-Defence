#pragma once
#include "Manager.h"
#include "IWaveInteractor.h"

class Wave;
class WaveInteractorManager : public Manager<IWaveInteractor>
{

public:
	WaveInteractorManager(void);
	~WaveInteractorManager(void);

	void interactAll(Wave ** waves,int size);
};

