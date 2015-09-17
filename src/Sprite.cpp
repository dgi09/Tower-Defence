#include "Sprite.h"
#include "TextureLoader.h"
#include "TexturePool.h"

Sprite::Sprite(void)
{
	texture = NULL;
	setX(0);
	setY(0);

	setVisible(true);
}


Sprite::~Sprite(void)
{
	//DestroyTexture();
}

void Sprite::DestroyTexture()
{
	if(texture != NULL)
		SDL_DestroyTexture(texture);
}
void Sprite::setPosition(double x,double y)
{
	px = x;
	py = y;
	area.x = (int)px;
	area.y = (int)py;

	onAreaChange();
}
int Sprite::getX()
{
	return area.x;
}
int Sprite::getY()
{
	return area.y;
}

void Sprite::setX(double x)
{
	px = x;
	area.x = (int)px;
	onAreaChange();
}
void Sprite::setY(double y)
{
	py = y;
	area.y = (int)py;
	onAreaChange();
}

void Sprite::move(double offsetX,double offsetY)
{
	setPosition(px + offsetX,py + offsetY);
}

void Sprite::setWidth(int width)
{
	area.w = width;
	onAreaChange();
}
int Sprite::getWidth()
{
	return area.w;
}

void Sprite::setHeight(int height)
{
	area.h = height;
	onAreaChange();
}
int Sprite::getHeight()
{
	return area.h;
}

void Sprite::setVisible(bool visible)
{
	this->visible = visible;
}
bool Sprite::isVisible()
{
	return visible;
}

void Sprite::draw(SDL_Renderer * renderer)
{
	if(isVisible())
	SDL_RenderCopy(renderer,texture,NULL,&area);
}

int Sprite::getLeft()
{
	return area.x;
}
int Sprite::getRight()
{
	return area.x + area.w;
}
int Sprite::getTop()
{
	return area.y;
}
int Sprite::getBottom()
{
	return area.y + area.h;
}

void Sprite::loadTextureFromFile(const char * fileName)
{
	texture = TexturePool::getPtr()->getTexture(fileName,area.w,area.h);
}

int Sprite::getCenterX()
{
	return getX() + getWidth()/2;
}

int Sprite::getCenterY()
{
	return getY() + getHeight()/2;
}

bool Sprite::colide(Sprite * sprite)
{
	bool colide = false;

	if(SDL_HasIntersection(&area,&sprite->area))
		colide = true;

	return colide;
}

void Sprite::onAreaChange()
{

}

double Sprite::getDistanceFromCentral(Sprite * sprite)
{
	double vecX = sprite->getCenterX() - getCenterX();
	double vecY = sprite->getCenterY() - getCenterY();
	double distance = SDL_sqrt(vecX * vecX + vecY * vecY);
	return distance;
}

void Sprite::centerToPoint(double x,double y)
{
	px = x - getWidth()/2;
	py = y - getHeight()/2;

	setPosition(px,py);
}