#pragma once


#include "DrawableObjectManager.h"
#include "UpdateableObjectManager.h"
#include "WaveInteractorManager.h"
#include "Manager.h"
#include "IClickable.h"

class ArenaInternalMenager
{
	DrawableObjectManager * drawableObjects;

	UpdateableObjectManager * updateableObjects;
	WaveInteractorManager * waveInteractors;
	Manager<IClickable> * clickableObjects;

public:
	void init(DrawableObjectManager * dObjMgr,UpdateableObjectManager * uObjMgr,WaveInteractorManager * wIntMgr,
		Manager<IClickable> * clObjMgr);

	void addDrawableObject(IDrawable * obj);
	void removeDrawableObject(IDrawable * obj);

	void addUpdateableObject(IUpdateable * obj);
	void removeUpdateableObject(IUpdateable * obj);

	void addWaveInteractor(IWaveInteractor * obj);
	void removeWaveInteractor(IWaveInteractor * obj);

	void addClickableObject(IClickable * obj);
	void removeClickableObject(IClickable * obj);

};

