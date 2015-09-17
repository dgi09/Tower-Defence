#pragma once
#include "IDrawable.h"

class Sprite : public IDrawable
{
private:
	double px,py;
	bool visible;

protected:

	SDL_Texture * texture;
	SDL_Rect area;
	
public:
	Sprite(void);
	virtual ~Sprite(void);

	void setPosition(double x,double y);
	int getX();
	int getY();

	void setX(double x);
	void setY(double y);

	void move(double offsetX,double offsetY);

	void setWidth(int width);
	int getWidth();

	void setHeight(int height);
	int getHeight();

	void setVisible(bool visible);
	bool isVisible();

	virtual void draw(SDL_Renderer * renderer);

	int getLeft();
	int getRight();
	int getTop();
	int getBottom();
	int getCenterX();
	int getCenterY();
	
	void loadTextureFromFile(const char * fileName);

	bool colide(Sprite * sprite);

	double getDistanceFromCentral(Sprite * sprite);

	void centerToPoint(double x,double y);
	

protected:
	void DestroyTexture();
	virtual void onAreaChange();
	

};

