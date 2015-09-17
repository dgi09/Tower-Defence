#include "TextSprite.h"


TextSprite::TextSprite(void) : Sprite()
{

}


TextSprite::~TextSprite(void)
{
	font = NULL;
	SDL_DestroyTexture(texture);
}


void TextSprite::setText(std::string text)
{
	if(this->text != text)
	{
		this->text = text;
		hadChanged = true;

		TTF_SizeText(font,this->text.c_str(),&area.w,&area.h);
	}
	
}
std::string  TextSprite::getText()
{
	return text;
}

void TextSprite::appentText(std::string text)
{

	setText(this->text + text);


}
void TextSprite::setFont(TTF_Font * font)
{
	if(font != NULL)
		this->font = font;
}

void TextSprite::draw(SDL_Renderer * renderer)
{
	if(hadChanged == true)
		reCreate(renderer);

	if(texture != NULL)
	SDL_RenderCopy(renderer,texture,NULL,&area);
}

void TextSprite::reCreate(SDL_Renderer * renderer)
{
	SDL_Surface * surface = TTF_RenderText_Solid(font,text.c_str(),color);
	area.h = surface->h;
	area.w = surface->w;

	texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	hadChanged = false;
}

void TextSprite::setColor(SDL_Color color)
{
	this->color = color;
}
void TextSprite::setColor(int r,int g,int b,int a)
{
	color.r = r;
	color.b = b;
	color.g = g;
	color.a = a;
}

void TextSprite::init()
{
	font = NULL;
	text = "";
	hadChanged = false;
	setPosition(0,0);
}
