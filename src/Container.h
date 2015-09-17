#pragma once
#include "Widget.h"
#include <vector>


class Container :public Widget
{
protected:
	std::vector<Widget*> widgets;
	std::vector<Widget*>::iterator it;

	SDL_Color bgColor;

	SDL_Texture * renderTarget;


public:

	Container(void);
	virtual ~Container(void);

	virtual void onEvent(GuiEvent & evt);
	virtual void draw(SDL_Renderer * renderer);

	void addWidget(Widget * child);
	void removeWidget(Widget * child);
	void removeWidget(std::string name);
	void removeAllWidgets();

	Widget * getChild(std::string name);
	Widget * getChild(int index);

	void setBGColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a);
};

