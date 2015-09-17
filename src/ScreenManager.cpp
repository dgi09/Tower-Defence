#include "ScreenManager.h"


ScreenManager * ScreenManager::ptr = NULL;
ScreenManager::ScreenManager(void)
{
	currentScreen = NULL;
	rendPtr = NULL;
	needNew = false;
}


ScreenManager::~ScreenManager(void)
{
	deleteCurrentScreen();
}


void ScreenManager::deleteCurrentScreen()
{
	if(currentScreen != NULL)
	{
		currentScreen->onClose();
		delete currentScreen;
		currentScreen = NULL;
	}
}

void ScreenManager::drawActiveScreen()
{
	if(rendPtr != NULL)
	currentScreen->draw(rendPtr);
}

void ScreenManager::initActiveScreen()
{
	currentScreen->init(windPtr);
}

void ScreenManager::updateActiveScreen()
{
	currentScreen->update();
}
void ScreenManager::closeActiveScreen()
{
	currentScreen->onClose();
}
void ScreenManager::pauseActiveScreen()
{
	currentScreen->onPause();
}

void ScreenManager::setRenderer(SDL_Renderer * renderer)
{
	rendPtr = renderer;
}

void ScreenManager::setWindow(SDL_Window * window)
{
	windPtr = window;
}

void ScreenManager::setActiveScreen(IScreen * screen)
{
	needNew = true;
	newScreen = screen;
	
}

ScreenManager * ScreenManager::getPtr()
{
	if(ptr == NULL)
		ptr = new ScreenManager;

	return ptr;
}
void ScreenManager::Destroy()
{
	if(ptr != NULL)
	{
		delete ptr;
		ptr = NULL;
	}
}

void ScreenManager::fireEventToActiveScreen(SDL_Event & evt)
{
	currentScreen->onEvent(evt);
}

bool ScreenManager::screenRequestAppStop()
{
	return currentScreen->requestAppStop();
}

void ScreenManager::reevluate()
{
	if(needNew)
	{
		deleteCurrentScreen();
		currentScreen = newScreen;

		initActiveScreen();

		needNew = false;
	}
}
