#pragma once

#include "IDrawable.h"
#include "GuiEvent.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <set>


class Widget :public IDrawable
{
private:

	std::unordered_map<int,std::vector<ISubscriber*>> subs;
	std::set<int> subsTypes;

	
	std::string name;
	int id;
	bool active;
	bool visible;

	SDL_Color borderColor;
	
protected:

	bool borderVisible;
	SDL_Rect area;
	void addSubscriber(int id,ISubscriber * subscriber);
	void deleteAllSubscribers();
	void callSubscriber(int id);

	virtual void onPositionChange();
	virtual void onSizeChange();

	void drawBorder(SDL_Renderer * renderer);

public:

	Widget(void);
	virtual ~Widget(void);

	virtual void onEvent(GuiEvent & evt) = 0;
	virtual void draw(SDL_Renderer * renderer) = 0;

	SDL_Rect getArea();
	void setArea(SDL_Rect area);

	void setPosition(int x,int y);

	int getX();
	int getY();


	void setWidth(int width);
	void setHeight(int height);

	int getWidth();
	int getHeight();

	void setName(std::string name);
	std::string getName();

	bool isPointInside(int x,int y);


	bool isActive();
	bool isVisible();

	void setActive(bool active);
	void setVisible(bool visible);

	void setId(int id);
	int getId();

	void showBorder(bool val);
	void setBorderColor(SDL_Color color);
	void setBorderColor(int r,int g,int b,int a);
	SDL_Color getBorderColor();

};

