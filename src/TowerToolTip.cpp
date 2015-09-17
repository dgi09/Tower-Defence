#include "TowerToolTip.h"


TowerToolTip::TowerToolTip(void):Sprite()
{

}


TowerToolTip::~TowerToolTip(void)
{
	if(texture != NULL)
	SDL_DestroyTexture(texture);
}

void TowerToolTip::draw(SDL_Renderer * renderer)
{
	if(texture == NULL)
	{
		texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_UNKNOWN,SDL_TEXTUREACCESS_TARGET,area.w,area.h);
	}

	SDL_Texture * callerTarget = SDL_GetRenderTarget(renderer);

	SDL_SetRenderTarget(renderer,texture);
	SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
	SDL_RenderClear(renderer);

	SDL_SetRenderTarget(renderer,callerTarget);
	SDL_RenderCopy(renderer,texture,NULL,&area);
}

void TowerToolTip::setRed()
{
	color.r = 255;
	color.a = 255;
	color.g = 0;
	color.b = 0;
}
void TowerToolTip::setGreen()
{
	color.r = 0;
	color.a = 255;
	color.g = 255;
	color.b = 0;
}