#include "ArenaInternalMenager.h"

void ArenaInternalMenager::init(DrawableObjectManager * dObjMgr,UpdateableObjectManager * uObjMgr,WaveInteractorManager * wIntMgr, Manager<IClickable> * clObjMgr)
{
	drawableObjects = dObjMgr;
	updateableObjects = uObjMgr;
	waveInteractors = wIntMgr;
	clickableObjects = clObjMgr;

}

void ArenaInternalMenager::addDrawableObject(IDrawable * obj)
{
	drawableObjects->addElement(obj);
}

void ArenaInternalMenager::removeDrawableObject(IDrawable * obj)
{
	drawableObjects->removeElement(obj);
}

void ArenaInternalMenager::addUpdateableObject(IUpdateable * obj)
{
	updateableObjects->addElement(obj);
}

void ArenaInternalMenager::removeUpdateableObject(IUpdateable * obj)
{
	updateableObjects->removeElement(obj);
}

void ArenaInternalMenager::addWaveInteractor(IWaveInteractor * obj)
{
	waveInteractors->addElement(obj);
}

void ArenaInternalMenager::removeWaveInteractor(IWaveInteractor * obj)
{
	waveInteractors->removeElement(obj);
}

void ArenaInternalMenager::addClickableObject(IClickable * obj)
{
	clickableObjects->addElement(obj);
}

void ArenaInternalMenager::removeClickableObject(IClickable * obj)
{
	clickableObjects->removeElement(obj);
}
