#pragma once
#include "MenuElement.h"
#include <vector>
#include "Container.h"


class Menu
{
	std::vector<MenuElement*> elements;
	std::vector<MenuElement*>::iterator it;

	Container container;
	int bottom;
public:
	Menu(void);
	~Menu(void);

	void init();
	void addMenuElement(MenuElement * element);
	void deleteMenuElement(MenuElement * element);
	void removeElement(MenuElement * element);
	Container * GetContainer();

	void hide();
	void show();

private:
	void repositionElements();
};

