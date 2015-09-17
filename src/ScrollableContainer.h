#pragma once 
#include "Container.h"
#include "SDL.h"


class ScrollableContainer : public Container
{
	SDL_Texture * childAreaTexture;
	SDL_Rect childArea;
	
	SDL_Rect hScrollRect;
	SDL_Rect vScrollRect;

	SDL_Color scrollColor;

	double hCoef,vCoef;
	bool hScroll,vScroll;
	bool hDrag,vDrag;
	int prevMx,prevMy;

public:
	ScrollableContainer();
	~ScrollableContainer();

	virtual void onEvent(GuiEvent & evt);

	virtual void draw(SDL_Renderer * renderer);

	void recalculate();

	void setScrollColor(int r,int g,int b);

private:

	bool pointInRect(int x,int y,SDL_Rect r);
	void moveAllChildren(int offsetX,int offsetY);

};
