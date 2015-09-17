#include "IObservee.h"
#include "IObserver.h"


IObservee::~IObservee()
{
	observers.clear();
}

void IObservee::addObserver(IObserver * observer)
{
	observers.push_back(observer);
}

void IObservee::removeObserver(IObserver * observer)
{
	for(it = observers.begin();it != observers.end();++it)
	{
		if((*it) == observer)
		{
			it = observers.erase(it);
			if(it == observers.end())
				break;
		}
	}

}

void IObservee::notify(int type)
{
	for(it = observers.begin();it != observers.end();++it)
	{
		if((*it) != 0)
			(*it)->observeeChange(type);
	}
}