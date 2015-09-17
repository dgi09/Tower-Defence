#include "Widget.h"
#include "TexturePool.h"

Widget::Widget(void)
{
	id = -1;

	area.x = 0;
	area.y = 0;

	name = "Unknown";
	setActive(true);
	setVisible(true);
	showBorder(false);
	setBorderColor(255,255,255,255);
}


Widget::~Widget(void)
{
	deleteAllSubscribers();
}


SDL_Rect Widget::getArea()
{
	return area;
}

void Widget::setArea(SDL_Rect area)
{
	this->area = area;
}

int Widget::getX()
{
	return area.x;
}

int Widget::getY()
{
	return area.y;
}

void Widget::setPosition(int x,int y)
{
	area.x = x;
	area.y = y;

	onPositionChange();
}

void Widget::setWidth(int width)
{
	area.w = width;
	onSizeChange();
}

void Widget::setHeight(int height)
{
	area.h = height;
	onSizeChange();
}

int Widget::getWidth()
{
	return area.w;
}
	
int Widget::getHeight()
{
	return area.h;
}

void Widget::setName(std::string name)
{
	this->name = name;
}
std::string Widget::getName()
{
	return name;
}

bool Widget::isPointInside(int x,int y)
{
	if(x >= area.x && x <= area.x + area.w && y >= area.y && y <= area.y + area.h)
	{
		return true;
	}
	else return false;
}


bool Widget::isActive()
{
	return active;
}

void Widget::setActive(bool active)
{
	this->active = active;
}

void Widget::setVisible(bool visible)
{
	this->visible = visible;
}

bool Widget::isVisible()
{
	return visible;
}


void Widget::addSubscriber(int id,ISubscriber * subscriber)
{
	subsTypes.insert(id);

	subscriber->setSender(this);
	subs[id].push_back(subscriber);
}

void Widget::deleteAllSubscribers()
{
	for(std::set<int>::iterator it = subsTypes.begin();it != subsTypes.end();++it)
	{
		for(int i = 0;i < subs[*it].size();i++)
		{
			if(subs[*it][i] != nullptr)
			{
				delete subs[*it][i];
			}
		}

		subs[*it].clear();
	}
}

void Widget::callSubscriber(int id)
{
	std::vector<ISubscriber*> & s = subs[id];

	for(unsigned int i = 0;i < subs[id].size();i++)
	{
		ISubscriber * subscriber = subs[id][i];
		subscriber->callback();
	}
}

void Widget::setId(int id)
{
	this->id = id;
}

int Widget::getId()
{
	return id;
}

void Widget::showBorder(bool val)
{
	borderVisible = val;
}

void Widget::setBorderColor(SDL_Color color)
{
	borderColor = color;
}

void Widget::setBorderColor(int r,int g,int b,int a)
{
	borderColor.r = r;
	borderColor.g = g;
	borderColor.a = a;
	borderColor.b = b;
}

SDL_Color Widget::getBorderColor()
{
	return borderColor;
}

void Widget::onPositionChange()
{

}

void Widget::onSizeChange()
{

}

void Widget::drawBorder(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer,borderColor.r,borderColor.g,borderColor.b,borderColor.a);
	SDL_RenderDrawRect(renderer,&area);
}
