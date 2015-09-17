#pragma once
#include <vector>

template<class T>
class Manager
{
protected:
	std::vector<T*> elements;
	typename std::vector<T*>::iterator it;


public:
	Manager(void);
	~Manager(void);

	T * getElementByIndex(int index);
	void addElement(T * element);
	void deleteElement(T * element);
	void removeElement(T * element);
	void deleteAllElements();
	void removeAllElements();

	int size();

	T** getArrayPointer();
};

template<class T>
T** Manager<T>::getArrayPointer()
{
	return elements.data();
}



template<class T> Manager<T>::Manager(void)
{
}


template<class T> Manager<T>::~Manager(void)
{

}

template<class T>
void Manager<T>::addElement(T * element)
{
	elements.push_back(element);
}

template<class T>
T *  Manager<T>::getElementByIndex(int index)
{
	if(index < elements.size())
		return elements[index];
	else return NULL;
}



template<class T>
void Manager<T>::deleteElement(T * element)
{
	for(it = elements.begin();it != elements.end();++it)
	{
		if((*it) == element)
		{
			delete (*it);
			(*it) = NULL;
			it = elements.erase(it);
			if(it == elements.end())
			break;
		}
	}
}

template<class T>
void Manager<T>::removeElement(T * element)
{
	for(it = elements.begin();it != elements.end();++it)
	{
		if((*it) == element)
		{
			it = elements.erase(it);
			if(it == elements.end())
			break;
		}
	}
}

template<class T> 
void Manager<T>::deleteAllElements()
{
	for(it = elements.begin();it != elements.end();++it)
	{

		delete (*it);
		(*it) = NULL;

	}

	elements.clear();
}

template<class T>
void Manager<T>::removeAllElements()
{
	elements.clear();
}

template<class T>
int Manager<T>::size()
{
	return elements.size();
}