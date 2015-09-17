#include "GUISystem.h"



GUISystem * GUISystem::ptr = NULL;

GUISystem::GUISystem(void)
{
	sheet = NULL;
	defaultFont = NULL;
}


GUISystem::~GUISystem(void)
{

	if(defaultFont != NULL)
	{
		TTF_CloseFont(defaultFont);
	}
	for(it = widgets.begin();it != widgets.end();++it)
	{
		if((*it) != NULL)
			delete (*it);

		it = widgets.erase(it);

		if(it == widgets.end())
			break;
	}

}

GUISystem * GUISystem::getPtr()
{
	if(ptr == NULL)
	ptr = new GUISystem;

	return ptr;
}

void GUISystem::Destroy()
{
	if(ptr != NULL)
	{
		delete ptr;
		ptr = NULL;
	}
}

void GUISystem::setGUISheet(Widget * sheet)
{
	this->sheet = sheet;
}

void GUISystem::deleteWidget(Widget * widget)
{
	for(it = widgets.begin();it != widgets.end();++it)
	{
		if((*it) == widget)
		{
			if((*it) != NULL)
			{
				delete (*it);
				(*it) = NULL;

				widgets.erase(it);
				break;
			}
		}
	}
}


void GUISystem::drawGUI(SDL_Renderer * renderer)
{
	sheet->draw(renderer);
}

void GUISystem::injectMousePos(int x,int y)
{
	ev.mouse.x = x;
	ev.mouse.y = y;
}

void GUISystem::injectMouseDown(MouseButton button)
{
	ev.mouse.type = BUTTON_DOWN;
	ev.mouse.button = button;

	sheet->onEvent(ev);
}

void GUISystem::injectMouseUp(MouseButton button)
{
	ev.mouse.type = BUTTON_UP;
	ev.mouse.button = button;

	sheet->onEvent(ev);
}

void GUISystem::injectMouseClick(MouseButton button)
{
	ev.type = MOUSE_EVENT;
	ev.mouse.type = CLICK;
	ev.mouse.button = button;

	sheet->onEvent(ev);
}

void GUISystem::injectMouseMove(int x,int y)
{
	ev.type = MOUSE_EVENT;
	ev.mouse.type = MOUSE_MOVE;
	ev.mouse.x = x;
	ev.mouse.y = y;

	sheet->onEvent(ev);
}


void GUISystem::injectSDLEvent(SDL_Event & evt)
{
	if(evt.type == SDL_MOUSEBUTTONDOWN)
	{
		ev.mouse.x = evt.button.x;
		ev.mouse.y = evt.button.y;

		ev.type = MOUSE_EVENT;

		injectMouseDown(LEFT);
		lastMouseState = SDL_MOUSEBUTTONDOWN;
	}


	if(evt.type == SDL_MOUSEBUTTONUP)
	{
		if(lastMouseState == SDL_MOUSEBUTTONDOWN)
		{
			ev.mouse.x = evt.button.x;
			ev.mouse.y = evt.button.y;

			ev.type = MOUSE_EVENT;
			ev.mouse.button = LEFT;
			injectMouseClick(ev.mouse.button);

		}
		else 
		{
			ev.mouse.x = evt.button.x;
			ev.mouse.y = evt.button.y;

			ev.type = MOUSE_EVENT;
			ev.mouse.button = LEFT;

			injectMouseUp(LEFT);
		}

		lastMouseState = SDL_MOUSEBUTTONUP;
	}

	if(evt.type == SDL_MOUSEMOTION)
	{
		injectMouseMove(evt.button.x,evt.button.y);
		lastMouseState = SDL_MOUSEMOTION;
	}


}

TTF_Font * GUISystem::getDefaultFont()
{
	if(defaultFont == NULL)
	{
		defaultFont = TTF_OpenFont("aparaj.ttf",16);
	}

	return defaultFont;
}

Button * GUISystem::createButton()
{
	Button * but = new Button();
	widgets.push_back(but);
	return but;
}

Label * GUISystem::createLabel()
{
	Label * l = new Label();
	widgets.push_back(l);
	return l;
}




