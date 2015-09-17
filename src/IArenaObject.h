#pragma once 

class ArenaInternalMenager;

class IArenaObject 
{
public:
	virtual void onArenaAdd(ArenaInternalMenager * mgr) = 0;
	virtual void onArenaRemove(ArenaInternalMenager * mgr) = 0;
};