#include "DrawableObjectManager.h"



DrawableObjectManager::DrawableObjectManager(void):Manager()
{
}


DrawableObjectManager::~DrawableObjectManager(void)
{
}

void DrawableObjectManager::drawAll(SDL_Renderer * renderer)
{
	if(!elements.empty())
	for(it = elements.begin();it != elements.end();++it)
	{
		(*it)->draw(renderer);
	}
}

