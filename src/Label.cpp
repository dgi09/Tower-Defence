#include "Label.h"

void Label::onEvent(GuiEvent & evt)
{

}

void Label::draw(SDL_Renderer * renderer)
{
	if(isVisible())
	{
		tSprite.draw(renderer);
		if(borderVisible)
			drawBorder(renderer);
	}
	
}

void Label::setText(std::string text)
{
	tSprite.setText(text);
	area.w = tSprite.getWidth();
	area.h = tSprite.getHeight();
}

void Label::setFont(TTF_Font * font)
{
	tSprite.setFont(font);
}

void Label::setColor(int r,int g,int b)
{
	tSprite.setColor(r,g,b,255);
}

Label::Label() : Widget()
{
	tSprite.setPosition(0,0);
}

Label::~Label()
{

}

void Label::onPositionChange()
{
	tSprite.setPosition(getX(),getY());
}

void Label::onSizeChange()
{
	tSprite.setWidth(getWidth());
	tSprite.setHeight(getHeight());
}
