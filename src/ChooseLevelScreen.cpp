#include "ChooseLevelScreen.h"
#include <string>
#include "PlayerGlobal.h"
#include "GUISystem.h"
#include "LevelsManager.h"
#include "GameScreen.h"
#include "ScreenManager.h"
#include "Label.h"

void ChooseLevelScreen::init(SDL_Window * window)
{
	setRequestAppStop(false);

	font = TTF_OpenFont("aparaj.ttf",40);
	labelsFont = TTF_OpenFont("aparaj.ttf",23);

	PlayerGlobal::getPtr()->calculateAllPoints();

	Label * lblPoints = GUISystem::getPtr()->createLabel();
	lblPoints->setFont(font);
	lblPoints->setColor(255,255,255);
	
	
	unsigned int pp = PlayerGlobal::getPtr()->getPoints();

	std::string t = "Points : " + std::to_string(pp);
	lblPoints->setText(t);
	lblPoints->setPosition(600,0);

	Label * lblCaption = GUISystem::getPtr()->createLabel();
	lblCaption->setFont(font);
	lblCaption->setColor(255,255,255);
	lblCaption->setPosition(50,0);
	lblCaption->setText("Choose level");

	screenFrame.addWidget(lblCaption);

	widgets.push_back(lblCaption);

	mainContainer.setPosition(50,50);
	mainContainer.setScrollColor(255,0,0);
	mainContainer.setWidth(700);
	mainContainer.setHeight(500);
	mainContainer.setBGColor(0,0,0,0);
	
	initLevelsButtons();

	mainContainer.recalculate();

	screenFrame.setBGColor(0,0,0,0);
	screenFrame.setPosition(0,0);
	screenFrame.setWidth(800);
	screenFrame.setHeight(588);

	screenFrame.addWidget(lblPoints);
	screenFrame.addWidget(&mainContainer);

	widgets.push_back(lblPoints);

	GUISystem::getPtr()->setGUISheet(&screenFrame);
}

void ChooseLevelScreen::update()
{
	
}

void ChooseLevelScreen::onEvent(SDL_Event & evt)
{
	GUISystem::getPtr()->injectSDLEvent(evt);
}

void ChooseLevelScreen::onClose()
{
	TTF_CloseFont(font);
	TTF_CloseFont(labelsFont);


	mainContainer.removeAllWidgets();

	for(unsigned int i = 0;i < widgets.size();i++)
	{
		GUISystem::getPtr()->deleteWidget(widgets[i]);
	}

	widgets.clear();
}

void ChooseLevelScreen::onPause()
{
	
}

void ChooseLevelScreen::onRestart()
{
	
}

void ChooseLevelScreen::draw(SDL_Renderer * renderer)
{
	SDL_RenderClear(renderer);
	GUISystem::getPtr()->drawGUI(renderer);
}

void ChooseLevelScreen::initLevelsButtons()
{
	int gap = 79;
	int x = gap;

	int y = 50;
	unsigned int pp = PlayerGlobal::getPtr()->getPoints();

	for(unsigned int i = 0;i < LevelsManager::getPtr()->getNumberOfLevels();i++)
	{
		Level level = LevelsManager::getPtr()->getLevelAt(i);
		Button * button = GUISystem::getPtr()->createButton();

		Label * label = GUISystem::getPtr()->createLabel();
		label->setColor(255,255,255);
		label->setFont(labelsFont);

		if(pp < level.requiredPoints)
		{
			button->loadImageFromFile("Data/Other/lock.png");
			button->setActive(false);
			label->setText("Required points : " + std::to_string(level.requiredPoints));
		}
		else 
		{
			std::string file = "Data/" + level.folder + "/map.bmp";
			button->loadImageFromFile(file.c_str());
			button->setWidth(128);
			button->setHeight(128);
			button->subsribeEvent(PRESS,new MemberSubsciber<ChooseLevelScreen>(&ChooseLevelScreen::onLevelClick,this));
			label->setText("Won points : " + std::to_string(level.wonPoints));
		}

		button->setPosition(x,y);
		button->setId(i);
		label->setPosition(button->getX() + 64 - label->getWidth()/2,y + 128 + 10);

		mainContainer.addWidget(button);
		mainContainer.addWidget(label);

		widgets.push_back(button);
		widgets.push_back(label);


		x += gap + 128;

		if((i+1) % 3 == 0)
		{
			x = gap;
			y += 128 + 50 + 10 + label->getHeight();
		}
	}
}

void ChooseLevelScreen::onLevelClick(Widget * widget)
{

	int id = widget->getId();
	Level level = LevelsManager::getPtr()->getLevelAt(id);

	GameScreen *gs = new GameScreen();
	gs->setFolder("Data/" + level.folder);
	gs->setLevelId(id);
	ScreenManager::getPtr()->setActiveScreen(gs);

}
