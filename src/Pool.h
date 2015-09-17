#pragma once 
#include <stdio.h>

template <class T>
class Pool
{
	unsigned int size;
	unsigned int currentAllocatedObjects;
	T * mem;
	bool * isFree;
public:
	Pool();
	~Pool();

	void Allocate(unsigned int size);
	T * New();
	void Delete(T * obj);

protected:
	void Resize(int size);

};

template <class T>
void Pool<T>::Resize(int size)
{
	T * buffer = new T[size];
	memcpy(buffer,mem,sizeof(T) * this->size);
	bool * freeBuffer = new bool[size];
	memcpy(freeBuffer,isFree,sizeof(bool) * this->size);

	delete[] mem;
	delete[] isFree;

	this->size = size;
	mem = buffer;
	isFree = freeBuffer;
}

template <class T>
void Pool<T>::Delete(T * obj)
{
	currentAllocatedObjects--;
	unsigned int loc = ((unsigned int)obj - (unsigned int)mem)/sizeof(T);
	isFree[loc] = true;
}

template <class T>
T * Pool<T>::New()
{
	if(currentAllocatedObjects == size)
	{
		Resize(size * 2);
	}

	currentAllocatedObjects++;
	unsigned int loc = 0;
	while(loc < size && isFree[loc] != true)
		loc++;

	isFree[loc] = false;
	//memset(&mem[loc],0,sizeof(T) * size);
	return &mem[loc];
}

template <class T>
void Pool<T>::Allocate(unsigned int size)
{
	this->size = size;
	mem = new T[size];
	isFree = new bool[size];

	for(int i = 0;i < size;i++)
		isFree[i] = true;
}

template <class T>
Pool<T>::~Pool()
{
	if(mem != nullptr)
		delete[] mem;

	if(isFree != nullptr)
		delete[] isFree;
}

template <class T>
Pool<T>::Pool()
{
	mem = nullptr;
	isFree = nullptr;
	currentAllocatedObjects = 0;
}

