#pragma once
#include "Pool.h"
#include "TexturePool.h"
#include "TextSprite.h"

class GlobalHeap
{
	static GlobalHeap * ptr;

	
public:
	static GlobalHeap * getPtr();
	static void Destroy();

	Pool<TextureObject> TextureObjects;
	
};

