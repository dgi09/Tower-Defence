#pragma once
#include "HUDElement.h"
#include "IObserver.h"
#include <string>
#include "TextSprite.h"
#include "Sprite.h"
#include "SDL_ttf.h"


class Player;

class PlayerStatHUD : public HUDElement , public IObserver
{
	TTF_Font * font;
	Player * pl;
	TextSprite lifeSprite;
	TextSprite goldSprite;

public:
	PlayerStatHUD(void);
	~PlayerStatHUD(void);

	void draw(SDL_Renderer * renderer);
	void init();
	void observeeChange(int type);

	void setPlayer(Player * player);
};

