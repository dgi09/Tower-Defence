#pragma once
#include "Sprite.h"

class TowerBase;

class Range : public Sprite
{
	double value;
	bool needReDraw;
public:
	Range(void);
	~Range(void);

	void reScale();
	void setValue(double val);
	double getValue();

	virtual void draw(SDL_Renderer * renderer);
	void generateTexture(SDL_Renderer * renderer);
};

