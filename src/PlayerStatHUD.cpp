#include "PlayerStatHUD.h"
#include "Player.h"

#include "GUISystem.h"
#include <strstream>

PlayerStatHUD::PlayerStatHUD(void) : HUDElement()
{
	
}


PlayerStatHUD::~PlayerStatHUD(void)
{
	TTF_CloseFont(font);
}

void PlayerStatHUD::setPlayer(Player * player)
{
	pl = player;
}

void PlayerStatHUD::init()
{
	font = TTF_OpenFont("aparaj.ttf",20);
	std::string lifeText = "Life : ";
	std::string goldText = "Gold : ";


	lifeSprite.setFont(font);
	lifeSprite.setColor(255,255,255,255);
	lifeSprite.setPosition(0,0);
	lifeSprite.setText(lifeText);

	goldSprite.setFont(font);
	goldSprite.setColor(255,255,255,255);
	goldSprite.setPosition(70,0);
	goldSprite.setText(goldText);

	



	setWidth(170);
	setHeight(30);
	setPosition(0,0);


}

void PlayerStatHUD::draw(SDL_Renderer * renderer)
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
	lifeSprite.draw(renderer);
	goldSprite.draw(renderer);
	

	SDL_SetRenderTarget(renderer,callerTarget);
	SDL_RenderCopy(renderer,texture,NULL,&area);

}

void PlayerStatHUD::observeeChange(int type)
{
	if(type == (int)HealthChange)
	{
		int playerLife = pl->getHealth();
		std::string lifeText = "Life : " + std::to_string(playerLife);
		lifeSprite.setText(lifeText);
	}

	if(type == (int)GoldChange)
	{
		int playerGold = pl->getGold();
		std::string goldText = "Gold : " + std::to_string(playerGold);
		goldSprite.setText(goldText);
	}
}