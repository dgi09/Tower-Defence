#pragma once


class Widget;

class MenuElement
{

public:
	MenuElement(void);
	virtual ~MenuElement(void);
	virtual void init() = 0;
	virtual Widget * getWidget() = 0;

	virtual void onDestroy() = 0;

};

