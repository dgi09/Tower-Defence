#pragma once
#include "Sprite.h"
#include <SDL_ttf.h>
#include <string>

class TextSprite : public Sprite
{

	TTF_Font * font;
	std::string text;
	SDL_Color color;
	bool hadChanged;
	
public:
	TextSprite(void);
	~TextSprite(void);

	void init();
	void setText(std::string text);
	std::string  getText();

	void appentText(std::string text);
	void setFont(TTF_Font * font);

	void draw(SDL_Renderer * renderer);

	void setColor(SDL_Color color);
	void setColor(int r,int g,int b,int a);
protected:
	void reCreate(SDL_Renderer * renderer);


};

