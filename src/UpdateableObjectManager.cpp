#include "UpdateableObjectManager.h"


UpdateableObjectManager::UpdateableObjectManager(void)
{
}


UpdateableObjectManager::~UpdateableObjectManager(void)
{
}

void UpdateableObjectManager::updateAll()
{
	for(it = elements.begin();it != elements.end();++it)
	{
		(*it)->update();
		if(it == elements.end())
			break;
	}
}
