#pragma once
#include "Manager.h"
#include "IUpdateable.h"

class UpdateableObjectManager : public Manager<IUpdateable>
{
public:
	UpdateableObjectManager(void);
	~UpdateableObjectManager(void);

	void updateAll();
};

