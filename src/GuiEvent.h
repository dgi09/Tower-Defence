#pragma once
#include <functional>

class Widget;

enum EventType
{
	MOUSE_EVENT,
	KEYBOARD_EVENT
};

enum KeyboardEventType
{
	KEY_DOWN,
	KEY_UP
};

struct Keyboard
{
	KeyboardEventType type;
	int key;
};

enum MouseEventType
{
	BUTTON_DOWN,
	BUTTON_UP,
	CLICK,
	MOUSE_MOVE
};

enum MouseButton
{
	LEFT,
	RIGHT
};

enum ButtonEvent
{
	PRESS = 0,
	MOUSE_IN,
	MOUSE_OUT
};
struct Mouse 
{
	MouseEventType type;
	MouseButton button;
	int x;
	int y;
};


struct GuiEvent
{
	EventType type;
	Keyboard key;
	Mouse mouse;
};

class ISubscriber
{
protected:
	Widget * sender;
public:
	virtual void callback() = 0;
	void setSender(Widget * sender);
};

class StaticSubscriber : public ISubscriber
{
	void (*function)(Widget * sender);
	
public:
	StaticSubscriber(void (*func)(Widget*),Widget * sender);
	StaticSubscriber(void (*func)(Widget*));

	void callback();
};

template <typename T>
class MemberSubsciber : public ISubscriber
{
	std::tr1::function<void(Widget*)> func;

public:
	MemberSubsciber(void (T::*f)(Widget*),T * obj,Widget * sender);
	MemberSubsciber(void (T::*f)(Widget*),T * obj);

	void callback();
};

template <typename T>
void MemberSubsciber<T>::callback()
{
	func(sender);
}

template <typename T>
MemberSubsciber<T>::MemberSubsciber(void (T::*f)(Widget*),T * obj)
{
	func = std::tr1::bind(f,obj,std::tr1::placeholders::_1);
}

template <typename T>
MemberSubsciber<T>::MemberSubsciber(void (T::*f)(Widget*),T * obj,Widget * sender)
{
	func = std::tr1::bind(f,obj,std::tr1::placeholders::_1);
	setSender(sender);
}
