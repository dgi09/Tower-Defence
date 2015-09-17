#pragma once
#include "Widget.h"
#include <map>
#include <vector>
#include "GuiEvent.h"
#include "Sprite.h"

class Button :public Widget
{
	Sprite sprite;
	bool mouseIn;
public:
	Button(void);
	~Button(void);

	void onEvent(GuiEvent & evt);
	virtual void draw(SDL_Renderer * renderer);

	void subsribeEvent(ButtonEvent evt,ISubscriber* subscriber);
	void loadImageFromFile(const char * fileName);

protected:
	virtual void onPositionChange();

	virtual void onSizeChange();

};

