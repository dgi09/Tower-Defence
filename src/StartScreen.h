#pragma once
#include "IScreen.h"
#include "Container.h"
#include "GUISystem.h"


class StartScreen : public IScreen
{
	Container mainContainer;
	Button * startButton;
	Button * closeButton;

	bool startClicked;
	bool closeClicked;

public:
	StartScreen(void);
	~StartScreen(void);

	virtual void draw(SDL_Renderer * renderer);

	virtual void init(SDL_Window * window);

	virtual void update();

	virtual void onEvent(SDL_Event & evt);

	virtual void onClose();

	virtual void onPause();

	virtual void onRestart();

protected:

	void onStartButtonClicked(Widget * sender);
	void onCloseButtonClicked(Widget * sender);

};

