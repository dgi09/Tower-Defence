#include "IClickable.h"
#include "SDL.h"

bool IClickable::pointInside(int x,int y)
{
	SDL_Rect area = getInteractionArea();
	if(area.x <= x && x <= area.x + area.w && area.y <= y && y <= area.y + area.h)
		return true;
	else return false;
}