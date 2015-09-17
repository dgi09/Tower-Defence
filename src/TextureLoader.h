#pragma once
#include <SDL.h>

class TextureLoader
{
	TextureLoader(void);
	static TextureLoader * ptr;
	SDL_Renderer * ptrRendr;
public:

	~TextureLoader(void);
	static TextureLoader * getPtr();
	static void ReleaseData();

	void loadTextureFromFile(const char * fileName,SDL_Texture ** textureToLoad,int & h,int & w);
	void loadPNG(const char * fileName,SDL_Texture ** textureToLoad,int & w,int & h);
	void setRenderer(SDL_Renderer * rnd);
};

