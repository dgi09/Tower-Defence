#pragma once

struct SDL_Rect;

class IClickable
{
public:
	virtual void onClick() = 0;
	virtual void onOutOfFocus() = 0;
	virtual SDL_Rect getInteractionArea() = 0;
	bool pointInside(int x,int y);
};