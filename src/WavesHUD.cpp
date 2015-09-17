#include "WavesHUD.h"
#include <sstream>
#include <iomanip>

void WavesHUD::observeeChange(int type)
{
	if(type == (int)Tick && finalWave == false)
	{
		
		double time = wavesMgr->getTimeToNextWave();
		std::ostringstream out;
		out << std::setprecision(2) << time;

		std::string t = "Next wave in : " + out.str() + " s";

		text.setText(t);
	}

	if(type == (int)FinalWave)
	{
		std::string t = "No more waves";
		text.setText(t);
		finalWave = true;
		
	}
}

void WavesHUD::draw(SDL_Renderer * renderer)
{
	if(texture == NULL)
	{
		texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_UNKNOWN,SDL_TEXTUREACCESS_TARGET,
			area.w,area.h);
	}

	SDL_Texture * callerTarget = SDL_GetRenderTarget(renderer);
	SDL_SetRenderTarget(renderer,texture);
	SDL_SetRenderDrawColor(renderer,0,0,0,0);
	SDL_RenderClear(renderer);

	text.draw(renderer);

	SDL_SetRenderTarget(renderer,callerTarget);
	SDL_RenderCopy(renderer,texture,NULL,&area);
}

void WavesHUD::init()
{
	font = TTF_OpenFont("aparaj.ttf",20);
	text.setFont(font);
	text.setColor(255,255,255,255);
	text.setPosition(0,0);

	setWidth(130);
	setHeight(30);

	finalWave = false;
}

void WavesHUD::setWavesManager(WaveManager * mgr)
{
	this->wavesMgr = mgr;
}

WavesHUD::WavesHUD() : HUDElement()
{

}

WavesHUD::~WavesHUD()
{
	TTF_CloseFont(font);
}
