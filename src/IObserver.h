#pragma once 

class IObserver
{
public:
	virtual void observeeChange(int type) = 0;
};