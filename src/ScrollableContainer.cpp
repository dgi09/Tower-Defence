#include "ScrollableContainer.h"

void ScrollableContainer::onEvent(GuiEvent & evt)
{
	if(evt.type == MOUSE_EVENT)
	{
		int mX = evt.mouse.x - getX();
		int mY = evt.mouse.y - getY();

		if(evt.mouse.type == CLICK)
		{
			if(mX <= childArea.w && mY <= childArea.h)
			{
				for(it = widgets.begin();it != widgets.end();++it)
				{
					if((*it)->isActive())
					{
						evt.mouse.x -= getX();
						evt.mouse.y -= getY();


						if((*it)->isPointInside(evt.mouse.x,evt.mouse.y))
						{
							(*it)->onEvent(evt);
						}

						evt.mouse.x += getX();
						evt.mouse.y += getY();


					}
				}
			}
		}
		
		if(hScroll || vScroll)
		{
			if(evt.mouse.type == BUTTON_DOWN)
			{
				if(hScroll && pointInRect(mX,mY,hScrollRect))
				{
					vDrag = false;
					hDrag = true;

					prevMx = mX;
					prevMy = mY;
				}

				if(vScroll && pointInRect(mX,mY,vScrollRect))
				{
					vDrag = true;
					hDrag = false;

					prevMx = mX;
					prevMy = mY;
				}
			}

			if(evt.mouse.type == MOUSE_MOVE)
			{
				if(vDrag)
				{
					int am = mY - prevMy;

					if(am < 0)
					{
						if(vScrollRect.y + am < 0)
							am = -vScrollRect.y;
					}
					else if(am > 0)
					{
						if(vScrollRect.y + vScrollRect.h + am > childArea.h)
							am = childArea.h - vScrollRect.h - vScrollRect.y;
					}

					int chAm = am * -1.0 * vCoef;
					vScrollRect.y += am;

					moveAllChildren(0,chAm);
				}

				if(hDrag)
				{
					int am = mX - prevMx;

					if(am < 0)
					{
						if(hScrollRect.x + am < 0)
							am = -hScrollRect.x;
					}
					else if(am > 0)
					{
						if(hScrollRect.x + hScrollRect.w + am > childArea.w)
							am = childArea.w - hScrollRect.w - hScrollRect.x;
					}

					int chAm = am * -1.0 * hCoef;
					hScrollRect.x += am;

					moveAllChildren(chAm,0);
				}

				prevMx = mX;
				prevMy = mY;
			}

			if(evt.mouse.type == BUTTON_UP)
			{
				vDrag = false;
				hDrag = false;
			}
		}
		
	}
}

void ScrollableContainer::draw(SDL_Renderer * renderer)
{
	if(isVisible())
	{
		if(renderTarget == NULL)
		{
			renderTarget = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_UNKNOWN,SDL_TEXTUREACCESS_TARGET,getWidth(),getHeight());
		}

		if(childAreaTexture == nullptr)
		{
			childAreaTexture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_UNKNOWN,SDL_TEXTUREACCESS_TARGET,childArea.w,childArea.h);
		}

		SDL_Texture * callerTexture = SDL_GetRenderTarget(renderer);

		SDL_SetRenderTarget(renderer,renderTarget);

		SDL_SetRenderDrawColor(renderer,bgColor.r,bgColor.g,bgColor.b,bgColor.a);

		SDL_RenderClear(renderer);


		SDL_SetRenderTarget(renderer,childAreaTexture);
		SDL_RenderClear(renderer);


		for(it = widgets.begin();it != widgets.end();++it)
		{
			(*it)->draw(renderer);
		}

		SDL_Color prevColor;

		SDL_SetRenderTarget(renderer,renderTarget);
		SDL_RenderCopy(renderer,childAreaTexture,nullptr,&childArea);

		if(vScroll || hScroll)
		{
			SDL_GetRenderDrawColor(renderer,&prevColor.r,&prevColor.g,&prevColor.b,&prevColor.a);

			SDL_SetRenderDrawColor(renderer,scrollColor.r,scrollColor.g,scrollColor.b,scrollColor.a);
			if(vScroll)
			{
				SDL_RenderFillRect(renderer,&vScrollRect);
			}

			if(hScroll)
			{
				SDL_RenderFillRect(renderer,&hScrollRect);
			}

			SDL_SetRenderDrawColor(renderer,prevColor.r,prevColor.g,prevColor.b,prevColor.a);
		}

		if(borderVisible)
		{
			SDL_GetRenderDrawColor(renderer,&prevColor.r,&prevColor.g,&prevColor.b,&prevColor.a);

			SDL_SetRenderDrawColor(renderer,0,0,255,255);

			SDL_RenderDrawRect(renderer,&childArea);

			SDL_SetRenderDrawColor(renderer,prevColor.r,prevColor.g,prevColor.b,prevColor.a);
		}
		

		SDL_SetRenderTarget(renderer,callerTexture);

		SDL_RenderCopy(renderer,renderTarget,NULL,&getArea());
		callerTexture = NULL;
	}
}

void ScrollableContainer::recalculate()
{

	vScroll = hScroll = false;
	vDrag = hDrag  = false;
	int farRightPoint = 0;
	int farDownPoint = 0;

	childArea.x = childArea.y = 0;
	childArea.w = getWidth();
	childArea.h = getHeight();


	for(unsigned int i = 0;i < widgets.size();i++)
	{
		Widget * w = widgets[i];
		if(w->getX() + w->getWidth() > farRightPoint)
		{
			farRightPoint = w->getX() + w->getWidth();
		}

		if(w->getY() + w->getHeight() > farDownPoint)
		{
			farDownPoint = w->getY() + w->getHeight();
		}
	}
	
	if(farDownPoint > getHeight())
	{
		vScroll = true;
		childArea.w = getWidth() - 30;
		
	}

	if(farRightPoint > getWidth())
	{
		hScroll = true;
		childArea.h = getHeight() - 30;
		
	}

	if(vScroll)
	{
		double sizeCoef = (double)childArea.h / (double)farDownPoint;
		vScrollRect.w = 30;
		vScrollRect.h = childArea.h * sizeCoef;
		vScrollRect.x = getWidth() - 30;
		vScrollRect.y = 0;

		vCoef = (double)farDownPoint / (double)childArea.h;
	}

	if(hScroll)
	{
		double sizeCoef = (double)childArea.w / (double)farRightPoint;
		hScrollRect.h = 30;
		hScrollRect.w = childArea.w * sizeCoef;
		hScrollRect.x = 0;
		hScrollRect.y = getHeight() - 30;

		hCoef = (double)farRightPoint / (double)childArea.w;	
	}
}

void ScrollableContainer::setScrollColor(int r,int g,int b)
{
	scrollColor.r = r;
	scrollColor.g = g;
	scrollColor.b = b;
}

ScrollableContainer::ScrollableContainer() : Container()
{
	scrollColor.a = 255;

	childAreaTexture = nullptr;
	showBorder(true);

}

ScrollableContainer::~ScrollableContainer()
{
	if(childAreaTexture != nullptr)
	{
		SDL_DestroyTexture(childAreaTexture);
	}
}

bool ScrollableContainer::pointInRect(int x,int y,SDL_Rect r)
{
	if(x >= r.x && x <= r.x + r.w && y >= r.y && y <= r.y + r.h)
		return true;

	return false;
}

void ScrollableContainer::moveAllChildren(int offsetX,int offsetY)
{
	for(unsigned int i = 0;i < widgets.size();i++)
	{
		Widget * w = widgets[i];
		w->setPosition(w->getX() + offsetX,w->getY() + offsetY);
	}
}
