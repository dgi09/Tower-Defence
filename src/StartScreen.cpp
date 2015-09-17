#include "StartScreen.h"
#include "ScreenManager.h"
#include <functional>
#include "GuiEvent.h"
#include "ChooseLevelScreen.h"
#include "TexturePool.h"
#include <iostream>
#include "LevelsManager.h"
#include "GameScreen.h"


StartScreen::StartScreen(void)
{
}


StartScreen::~StartScreen(void)
{
}



void StartScreen::draw(SDL_Renderer * renderer)
{
	SDL_RenderClear(renderer);
	GUISystem::getPtr()->drawGUI(renderer);
}

void StartScreen::init(SDL_Window * window)
{
	SDL_ShowCursor(1);
	setRequestAppStop(false);

	mainContainer.setBGColor(255,0,0,0);
	mainContainer.setWidth(800);
	mainContainer.setHeight(588);

	startButton = GUISystem::getPtr()->createButton();
	startButton->setId(1);

	startButton->loadImageFromFile("Data/StartScreen/start.png");
	startButton->setPosition(250,100);
	startButton->subsribeEvent(PRESS,new MemberSubsciber<StartScreen>(&StartScreen::onStartButtonClicked,this));

	closeButton = GUISystem::getPtr()->createButton();
	closeButton->setId(2);
	closeButton->loadImageFromFile("Data/StartScreen/exit.png");
	closeButton->setPosition(250,280);
	closeButton->subsribeEvent(PRESS,new MemberSubsciber<StartScreen>(&StartScreen::onCloseButtonClicked,this));
	mainContainer.addWidget(startButton);
	mainContainer.addWidget(closeButton);

	GUISystem::getPtr()->setGUISheet(&mainContainer);
}

void StartScreen::update()
{
	/*if(startClicked)
	{
		GameScreen * gs = new GameScreen();
		gs->setFolder("Data/BasicMap");
		ScreenManager::getPtr()->setActiveScreen(gs);
	}

	if(closeClicked)
	{
		setRequestAppStop(true);
	}*/
}

void StartScreen::onEvent(SDL_Event & evt)
{
	GUISystem::getPtr()->injectSDLEvent(evt);
}

void StartScreen::onClose()
{
	mainContainer.removeWidget(startButton);
	mainContainer.removeWidget(closeButton);
	GUISystem::getPtr()->deleteWidget(startButton);
	GUISystem::getPtr()->deleteWidget(closeButton);

	TexturePool::getPtr()->clear();
}

void StartScreen::onPause()
{
	
}

void StartScreen::onRestart()
{
	
}

void StartScreen::onStartButtonClicked(Widget * sender)
{
	//startClicked = true;

	LevelsManager::getPtr()->init();

	ChooseLevelScreen * chLScreen = new ChooseLevelScreen();
	ScreenManager::getPtr()->setActiveScreen(chLScreen);

	
}

void StartScreen::onCloseButtonClicked(Widget * sender)
{
	//closeClicked = true;	

	setRequestAppStop(true);
}
