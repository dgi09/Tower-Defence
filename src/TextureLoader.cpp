#include "TextureLoader.h"
#include "SDL_image.h"

TextureLoader * TextureLoader::ptr = NULL;

TextureLoader::TextureLoader(void)
{
	
}


TextureLoader::~TextureLoader(void)
{
	ptrRendr = NULL;
}

TextureLoader * TextureLoader::getPtr()
{
	if(ptr == NULL)
		ptr = new TextureLoader;
	
	return ptr;
}

void  TextureLoader::loadTextureFromFile(const char * fileName,SDL_Texture ** textureToLoad,int & h,int & w)
{
	SDL_Surface * surface = SDL_LoadBMP(fileName);

	*textureToLoad = SDL_CreateTextureFromSurface(ptrRendr,surface);
	h = surface->h;
	w = surface->w;

	SDL_FreeSurface(surface);

}

void TextureLoader::setRenderer(SDL_Renderer * rnd)
{
	ptrRendr = rnd;
}

void TextureLoader::ReleaseData()
{
	if(ptr != NULL)
		delete ptr;
}

void TextureLoader::loadPNG(const char * fileName,SDL_Texture ** textureToLoad,int & w,int & h)
{
	SDL_Surface  * surface = IMG_Load(fileName);
	w = surface->w;
	h = surface->h;

	*textureToLoad = SDL_CreateTextureFromSurface(ptrRendr,surface);
	SDL_FreeSurface(surface);
}