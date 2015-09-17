#include "Menu.h"


Menu::Menu(void)
{
	bottom = NULL;
}


Menu::~Menu(void)
{

}

void Menu::addMenuElement(MenuElement * element)
{
	if(bottom + element->getWidget()->getHeight() <= container.getHeight())
	{
		Widget * el = element->getWidget();
		el->setPosition(0,bottom);
		bottom += el->getHeight();

		elements.push_back(element);
		container.addWidget(el);
	}
}

void Menu::deleteMenuElement(MenuElement * element)
{
	for(it = elements.begin();it != elements.end();++it)
	{
		if((*it) ==  element)
		{
			container.removeWidget(element->getWidget());
			delete (*it);
			break;
		}
	}
}

void Menu::removeElement(MenuElement * element)
{
	for(it = elements.begin();it != elements.end();++it)
	{
		if((*it) == element)
		{
			container.removeWidget(element->getWidget());
			elements.erase(it);
			repositionElements();
			break;
		}
	}
}

void Menu::hide()
{
	container.setVisible(false);
}

void Menu::show()
{
	container.setVisible(true);
}

void Menu::repositionElements()
{
	bottom = 0;
	for(it = elements.begin();it != elements.end();++it)
	{
		(*it)->getWidget()->setPosition(0,bottom);
		bottom += (*it)->getWidget()->getHeight();
	}
}

void Menu::init()
{
	container.setPosition(714,0);
	container.setWidth(158);
	container.setHeight(588);
	container.setBGColor(0,0,0,255);
}

Container * Menu::GetContainer()
{
	return &container;
}
