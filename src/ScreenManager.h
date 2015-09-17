#pragma once

#include "IScreen.h"
#include <stack>

class ScreenManager
{
	IScreen * currentScreen;
	IScreen * newScreen;

	SDL_Renderer * rendPtr;
	SDL_Window * windPtr;

	ScreenManager(void);

	static ScreenManager * ptr;

	bool needNew;
public:

	~ScreenManager(void);

	void setActiveScreen(IScreen * screen);

	void setRenderer(SDL_Renderer * renderer);
	void setWindow(SDL_Window * window);

	void drawActiveScreen();
	void initActiveScreen();
	void fireEventToActiveScreen(SDL_Event & evt);
	void updateActiveScreen();
	void closeActiveScreen();
	void pauseActiveScreen();

	bool screenRequestAppStop();
	static ScreenManager * getPtr();
	static void Destroy();

	void reevluate();
private:
	void deleteCurrentScreen();

};

