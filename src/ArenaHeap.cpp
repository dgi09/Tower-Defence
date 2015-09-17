#include "ArenaHeap.h"


ArenaHeap * ArenaHeap::ptr = nullptr;

ArenaHeap * ArenaHeap::getPtr()
{
	if(ptr == nullptr)
		ptr = new ArenaHeap;

	return ptr;
}

void ArenaHeap::destroy()
{
	if(ptr != nullptr)
		delete ptr;

	ptr = nullptr;
}
