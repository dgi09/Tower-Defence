#include "Container.h"

#include <iostream>


Container::Container(void):Widget()
{
	
	renderTarget = nullptr;
}


Container::~Container(void)
{
	removeAllWidgets();

	if(renderTarget != nullptr)
		SDL_DestroyTexture(renderTarget);
}

void Container::onEvent(GuiEvent & evt)
{

	evt.mouse.x -= getX();
	evt.mouse.y -= getY();

	for(it = widgets.begin();it != widgets.end();++it)
	{
		if((*it)->isActive())
		{
			if(evt.type == MOUSE_EVENT)
			{
				if(evt.mouse.type != MOUSE_MOVE)
				{
					if((*it)->isPointInside(evt.mouse.x,evt.mouse.y))
					{
						(*it)->onEvent(evt);
					}
				}
				else
				{
					
						(*it)->onEvent(evt);
				}
				

				

			}
			else 
			(*it)->onEvent(evt);
		}
	}

	evt.mouse.x += getX();
	evt.mouse.y += getY();
}

void Container::draw(SDL_Renderer * renderer)
{
	if(isVisible())
	{
		if(renderTarget == nullptr)
		{
			renderTarget = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_UNKNOWN,SDL_TEXTUREACCESS_TARGET,getWidth(),getHeight());
			SDL_SetTextureBlendMode(renderTarget,SDL_BLENDMODE_BLEND);
		}


		SDL_Texture * callerTexture = SDL_GetRenderTarget(renderer);

		SDL_SetRenderTarget(renderer,renderTarget);

		SDL_SetRenderDrawColor(renderer,bgColor.r,bgColor.g,bgColor.b,bgColor.a);

		SDL_RenderClear(renderer);

	
		for(it = widgets.begin();it != widgets.end();++it)
		{
			(*it)->draw(renderer);
		}

		SDL_SetRenderTarget(renderer,callerTexture);

		SDL_RenderCopy(renderer,renderTarget,NULL,&getArea());

		if(borderVisible)
		{
			SDL_Color bc = getBorderColor();
			SDL_SetRenderDrawColor(renderer,bc.r,bc.g,bc.b,bc.a);
			SDL_RenderDrawRect(renderer,&area);
		}

		callerTexture = NULL;
	}
}

void Container::addWidget(Widget * child)
{
	widgets.push_back(child);
}
void Container::removeWidget(Widget * child)
{
	if(widgets.empty() ==  false)
	for(it = widgets.begin();it != widgets.end();++it)
	{
		if((*it) == child)
		{
			widgets.erase(it);
			break;
		}
	}
}
void Container::removeWidget(std::string name)
{
	if(widgets.empty() ==  false)
	for(it = widgets.begin();it != widgets.end();++it)
	{
		if((*it)->getName() == name)
		{
			widgets.erase(it);
			break;
		}
	}
}

Widget * Container::getChild(std::string name)
{
	for(it = widgets.begin();it != widgets.end();++it)
	{
		if((*it)->getName() == name)
		{
			return (*it);
		}
	}

	return NULL;
}
Widget * Container::getChild(int index)
{
	if(index > widgets.size() - 1 || index < 0)
		return NULL;
	else 
	{
		return widgets[index];
	}
}

void Container::setBGColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a)
{
	bgColor.a = a;
	bgColor.r = r;
	bgColor.g = g;
	bgColor.b = b;
	
}

void Container::removeAllWidgets()
{
	widgets.clear();
}