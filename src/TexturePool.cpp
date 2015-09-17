#include "TexturePool.h"
#include "TextureLoader.h"

#include "GlobalHeap.h"

TexturePool * TexturePool::ptr = 0;

TexturePool * TexturePool::getPtr()
{
	if(ptr == 0)
		ptr = new TexturePool();

	return ptr;
}

TexturePool::TexturePool(void)
{

}


TexturePool::~TexturePool(void)
{
	clear();
}

void TexturePool::cleanUp()
{
	if(ptr != 0)
	{
		delete ptr;
		ptr = 0;
	}
}

SDL_Texture * TexturePool::getTexture(std::string filePath,int & w,int &h)
{
	for(it = objects.begin();it != objects.end();++it)
	{
		if((*it)->filePath == filePath)
		{
			h = (*it)->h;
			w = (*it)->w;
			return (*it)->texture;
		}
	}

	TextureObject * obj = GlobalHeap::getPtr()->TextureObjects.New();

	TextureLoader::getPtr()->loadPNG(filePath.c_str(),&obj->texture,obj->w,obj->h);
	obj->filePath = filePath;

	w = obj->w;
	h = obj->h;
	objects.push_back(obj);

	return obj->texture;
}

void TexturePool::clear()
{
	for(it = objects.begin();it != objects.end();++it)
	{
		if((*it) != NULL)
		{
			if((*it)->texture != NULL)
				SDL_DestroyTexture((*it)->texture);

			GlobalHeap::getPtr()->TextureObjects.Delete((*it));
		}
	}

	objects.clear();
}
