#include "GuiEvent.h"
#include "Widget.h"


StaticSubscriber::StaticSubscriber(void (*func)(Widget*),Widget * sender)
{
	setSender(sender);
	function = func;
}

StaticSubscriber::StaticSubscriber(void (*func)(Widget*))
{
	function = func;
}

void StaticSubscriber::callback()
{
	function(sender);
}


void ISubscriber::setSender(Widget * sender)
{
	this->sender = sender;
}
