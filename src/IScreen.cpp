#include "IScreen.h"



bool IScreen::requestAppStop()
{
	return reqAppStop;
}

void IScreen::setRequestAppStop(bool val)
{
	reqAppStop = val;
}
