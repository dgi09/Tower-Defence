#pragma once
#include <vector>

class IObserver;

class IObservee
{
	std::vector<IObserver*> observers;
	std::vector<IObserver*>::iterator it;

public:

	virtual ~IObservee();
	void addObserver(IObserver * observer);
	void removeObserver(IObserver * observer);

protected:

	void notify(int type);
};