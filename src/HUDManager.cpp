#include "HUDManager.h"


HUDManager::HUDManager(void):Manager()
{
}


HUDManager::~HUDManager(void)
{

}


void HUDManager::drawHud(SDL_Renderer * renderer)
{
	for(it = elements.begin();it != elements.end();++it)
	{
		(*it)->draw(renderer);
	}
}