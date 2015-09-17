#pragma once 
#include "IDrawable.h"


class IScreen : public IDrawable
{
	SDL_Texture * renderTarget;
	
	bool reqAppStop;
public:

	virtual void draw(SDL_Renderer * renderer) = 0;
	virtual void init(SDL_Window * window) = 0;

	virtual void update() = 0;
	virtual void onEvent(SDL_Event & evt) = 0;
	virtual void onClose() = 0;
	virtual void onPause() = 0;
	virtual void onRestart() = 0;

	bool requestAppStop();

protected:
	void setRequestAppStop(bool val);

};