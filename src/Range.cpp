#include "Range.h"
#include "TowerBase.h"
#include "TexturePool.h"
#include <cmath>

Range::Range(void):Sprite()
{
	needReDraw = true;
	value = 0;
}


Range::~Range(void)
{
	texture = NULL;
}

void Range::reScale()
{
	needReDraw = true;
}

void Range::setValue(double val)
{
	if(val != value)
	{
		value = val;
		reScale();
		setWidth(val * 2);
		setHeight(val * 2);
	}

}
double Range::getValue()
{
	return value;
}

void Range::draw(SDL_Renderer * renderer)
{
	if(isVisible())
	{
		if(needReDraw)
		{
			generateTexture(renderer);
			needReDraw = false;
		}

		SDL_RenderCopy(renderer,texture,nullptr,&area);
	}
}

void Range::generateTexture(SDL_Renderer * renderer)
{
	if(texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}

	setWidth(value * 2);
	setHeight(value * 2);

	SDL_Texture * prevRenderTarget = SDL_GetRenderTarget(renderer);
	texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_UNKNOWN,SDL_TEXTUREACCESS_TARGET,getWidth(),getHeight());
	SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND);

	SDL_SetRenderTarget(renderer,texture);
	SDL_SetRenderDrawColor(renderer,0,0,0,0);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer,255,0,0,255);

	

	for(double i = 0;i<=360;i+=0.01)
	{
		int x = value + value * cos(i);
		int y = value + value * sin(i);

		SDL_RenderDrawPoint(renderer,x,y);
	}




	SDL_SetRenderTarget(renderer,prevRenderTarget);
}
