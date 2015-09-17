#pragma once 
#include "MenuElement.h"

class Container;

class InfoPanel : public MenuElement
{
	Container * outerPanel;
	Container * prevPanel;
	Container * currentPanel;
	Container * empty;
public:
	InfoPanel();
	~InfoPanel();

	void init();

	Widget * getWidget();

	void onDestroy();

	void setActiveContainer(Container * c);
	void setActiveEmpty();
	void removeActiveContainer();

};