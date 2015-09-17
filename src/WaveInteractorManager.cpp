#include "WaveInteractorManager.h"
#include "Wave.h"

WaveInteractorManager::WaveInteractorManager(void):Manager()
{
}


WaveInteractorManager::~WaveInteractorManager(void)
{
}


void WaveInteractorManager::interactAll(Wave ** waves,int size)
{
	for(it = elements.begin();it != elements.end();++it)
	{
		(*it)->wavesInteract(waves,size);

		if(it == elements.end())
			break;
	}
}