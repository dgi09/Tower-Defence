#pragma once
#include <vector>
#include <SDL.h>
#include <string>


struct TextureObject
{
	SDL_Texture * texture;
	std::string filePath;
	int h,w;
};


class TexturePool
{
	std::vector<TextureObject*> objects;
	std::vector<TextureObject*>::iterator it;

	static TexturePool * ptr;
	TexturePool(void);
public:

	
	~TexturePool(void);

	void clear();

	SDL_Texture * getTexture(std::string filePath,int &w,int &h);

	static TexturePool * getPtr();

	static void cleanUp();

};

