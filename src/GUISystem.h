#pragma once


#include "Widget.h"
#include <vector>
#include "GuiEvent.h"
#include "SDL_ttf.h"
#include "Button.h"
#include "Label.h"

class GUISystem
{
	GUISystem(void);
	std::vector<Widget*> widgets;
	std::vector<Widget*>::iterator it;

	static GUISystem * ptr;
	
	Widget * sheet;
	GuiEvent ev;
	Uint32 lastMouseState;

	TTF_Font * defaultFont;
public:
	
	~GUISystem(void);

	void deleteWidget(Widget * widget);
	static GUISystem * getPtr();

	void setGUISheet(Widget * sheet);
	
	static void Destroy();

	void drawGUI(SDL_Renderer * renderer);
	
	void injectMousePos(int x,int y);
	void injectMouseDown(MouseButton button);
	void injectMouseUp(MouseButton button);
	void injectMouseClick(MouseButton button);
	void injectSDLEvent(SDL_Event & evt);
	void injectMouseMove(int x,int y);

	TTF_Font * getDefaultFont();

	// factory methods

	Button * createButton();
	Label * createLabel();
};

