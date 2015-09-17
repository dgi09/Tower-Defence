#include "Button.h"
#include <iostream>

Button::Button(void):Widget()
{
	mouseIn = false;
}


Button::~Button(void)
{

	
}


void Button::onEvent(GuiEvent & evt)
{
	if(evt.type == MOUSE_EVENT)
	{
		if(evt.mouse.type == CLICK)
		{
			callSubscriber((int)PRESS);
		}

		if(evt.mouse.type == MOUSE_MOVE)
		{
			if(!mouseIn && isPointInside(evt.mouse.x,evt.mouse.y))
			{
				mouseIn = true;
				callSubscriber((int)MOUSE_IN);
			}
			if(mouseIn && !isPointInside(evt.mouse.x,evt.mouse.y))
			{
				mouseIn = false;
				callSubscriber((int)MOUSE_OUT);
			}
		}
	}
}

void Button::draw(SDL_Renderer * renderer)
{
	if(isVisible())
	{
		sprite.draw(renderer);
		if(borderVisible)
		{
			drawBorder(renderer);
		}
	}
	
}

void Button::subsribeEvent(ButtonEvent evt,ISubscriber* subscriber)
{
	addSubscriber((int)evt,subscriber);
}

void Button::onPositionChange()
{
	sprite.setPosition(getX(),getY());
}

void Button::onSizeChange()
{
	sprite.setWidth(getWidth());
	sprite.setHeight(getHeight());
}

void Button::loadImageFromFile(const char * fileName)
{
	sprite.loadTextureFromFile(fileName);
	area.w = sprite.getWidth();
	area.h = sprite.getHeight();
}
