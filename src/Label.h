#pragma once 
#include "Widget.h"
#include "TextSprite.h"
#include <string>
#include <SDL_ttf.h>

class Label : public Widget
{
	TextSprite tSprite;
public:

	Label();
	~Label();

	virtual void onEvent(GuiEvent & evt);

	virtual void draw(SDL_Renderer * renderer);

	void setText(std::string text);
	void setFont(TTF_Font * font);
	void setColor(int r,int g,int b);

protected:
	virtual void onPositionChange();

	virtual void onSizeChange();

};
