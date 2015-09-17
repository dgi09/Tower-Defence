#include "MenuContainer.h"


MenuContainer::MenuContainer(void)
{

}


MenuContainer::~MenuContainer(void)
{
}



void MenuContainer::addElement(MenuElement * element)
{
	subElements.push_back(element);
	container->addWidget(element->getWidget());
}

void MenuContainer::removeElement(MenuElement * element)
{
	for(it = subElements.begin();it != subElements.end();++it)
	{
		if((*it) == element)
		{
			it = subElements.erase(it);
			container->removeWidget(element->getWidget());
			break;
		}
	}

}

void MenuContainer::removeAllElements()
{
	for(it = subElements.begin();it != subElements.end();++it)
	{
		container->removeWidget((*it)->getWidget());
		it = subElements.erase(it);
		break;
		
	}
}

void MenuContainer::deleteElement(MenuElement * element)
{
	for(it = subElements.begin();it != subElements.end();++it)
	{
		if((*it) == element)
		{

			element->onDestroy();
			container->removeWidget(element->getWidget());
			if((*it) != NULL)
				delete (*it);

			it = subElements.erase(it);
			break;
		}
	}
}
void MenuContainer::deleteAllElements()
{
	for(it = subElements.begin();it != subElements.end();++it)
	{
		(*it)->onDestroy();
		container->removeWidget((*it)->getWidget());
		if((*it) != NULL)
			delete (*it);
		it = subElements.erase(it);
	}
}

Widget * MenuContainer::getWidget()
{
	return container;
}