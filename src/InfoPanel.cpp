#include "InfoPanel.h"
#include "GUISystem.h"
#include "Container.h"



InfoPanel::InfoPanel()
{
	outerPanel = nullptr;
	currentPanel = nullptr;
}

InfoPanel::~InfoPanel()
{
	
}

void InfoPanel::init()
{
	outerPanel = new Container();
	outerPanel->setBGColor(0,0,0,255);
	outerPanel->setPosition(0,0);
	outerPanel->setWidth(158);
	outerPanel->setHeight(250);


	empty = new Container();
	empty->setBGColor(0,0,0,0);
	empty->setPosition(0,0);
	empty->setWidth(10);
	empty->setHeight(10);

	prevPanel = empty;

	outerPanel->addWidget(prevPanel);
	currentPanel = prevPanel;
}

Widget * InfoPanel::getWidget()
{
	return outerPanel;
}

void InfoPanel::onDestroy()
{
	if(outerPanel != nullptr)
		delete outerPanel;
	if(empty != nullptr)
		delete empty;

	prevPanel = nullptr;
}

void InfoPanel::setActiveContainer(Container * c)
{
	outerPanel->removeAllWidgets();
	prevPanel = currentPanel;
	currentPanel = c;
	outerPanel->addWidget(c);
}

void InfoPanel::removeActiveContainer()
{
	outerPanel->removeAllWidgets();
	currentPanel = prevPanel;

	outerPanel->addWidget(currentPanel);
}

void InfoPanel::setActiveEmpty()
{
	setActiveContainer(empty);
}
