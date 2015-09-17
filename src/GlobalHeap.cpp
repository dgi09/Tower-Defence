#include "GlobalHeap.h"


GlobalHeap * GlobalHeap::ptr = nullptr;

GlobalHeap * GlobalHeap::getPtr()
{
	if(ptr == nullptr)
		ptr = new GlobalHeap;

	return ptr;
}

void GlobalHeap::Destroy()
{
	if(ptr != nullptr)
		delete ptr;
	ptr = nullptr;
}
