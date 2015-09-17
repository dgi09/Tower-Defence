#pragma once
#include "MenuElement.h"
#include <vector>
#include "Container.h"



class MenuContainer : public MenuElement
{
protected:
	std::vector<MenuElement*> subElements;
	std::vector<MenuElement*>::iterator it;


	void addElement(MenuElement * element);
	void removeElement(MenuElement * element);
	void removeAllElements();

	void deleteElement(MenuElement * element);
	void deleteAllElements();

	Container * container;

public:
	MenuContainer(void);
	~MenuContainer(void);

	virtual void init() = 0;
	virtual Widget * getWidget();

	virtual void onDestroy() = 0;


};

