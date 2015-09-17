#include "SDL.h"
#include "Container.h"
#include "Button.h"

#include "TextureLoader.h"
#include <crtdbg.h>
#include <iostream>
#include "GuiEvent.h"

#include "ScreenManager.h"
#include "GameScreen.h"
#include "StartScreen.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "GlobalHeap.h"
#include "IScreen.h"
#include <chrono>

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
   
 
	SDL_Window * window = SDL_CreateWindow("Tower Defense",100,50,872,588,SDL_WINDOW_SHOWN);
	SDL_Renderer  * rend = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);


	SDL_ShowCursor(0);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);


	TextureLoader::getPtr()->setRenderer(rend);

	GlobalHeap::getPtr()->TextureObjects.Allocate(20);

	ScreenManager * mgr = ScreenManager::getPtr();
	mgr->setRenderer(rend);
	mgr->setWindow(window);
	


	mgr->setActiveScreen(new StartScreen());
	mgr->reevluate();

	bool end = false;
	SDL_Event e;
	
	
	while(!end)
	{
		
		auto begin = std::chrono::high_resolution_clock::now();

		mgr->reevluate();
		if(mgr->screenRequestAppStop())
		{
			break;
		}

		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				end = true;
				break;
			}

			mgr->fireEventToActiveScreen(e);

		}
	
		
		mgr->updateActiveScreen();

		SDL_SetRenderDrawColor(rend,0,0,0,255);
		mgr->drawActiveScreen();

		SDL_RenderPresent(rend);

		auto end = std::chrono::high_resolution_clock::now();

		int delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

		if(delta < 40)
			SDL_Delay(40 - delta);
	}

	ScreenManager::Destroy();
	GlobalHeap::getPtr()->Destroy();

	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(window);

	TTF_Quit();
	 SDL_Quit();
	_CrtDumpMemoryLeaks();
    return 0;
}