#pragma once 

#include "Sprite.h"
#include "TextSprite.h"
#include "IObserver.h"
#include "WaveManager.h"
#include "HUDElement.h"
#include <string>
#include "SDL_ttf.h"


class WavesHUD : public IObserver , public HUDElement
{
	TTF_Font * font;
	WaveManager * wavesMgr;
	TextSprite text;

	bool finalWave;
public:

	WavesHUD();
	~WavesHUD();

	void init();
	void observeeChange(int type);
	void draw(SDL_Renderer * renderer);

	void setWavesManager(WaveManager * mgr);



};