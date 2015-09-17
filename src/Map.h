#pragma once

#include "IDrawable.h"
#include <vector>


#define TILESX 17
#define TILESY 14
#define TILEWIDTH 42
#define TILEHEIGHT 42

class Road
{
	std::vector<SDL_Point> roadTiles;
public:
	void addRoadPoint(int x,int y);
	SDL_Point getPointAt(int index);
	int getRoadLenght();
};


class Map : public IDrawable
{
	SDL_Texture * mapTexture;
	SDL_Rect  area;
	std::vector<Road> roads;
	bool tiles[TILESY][TILESX];

public:
	Map(void);
	~Map(void);

	bool getTileAt(int x,int y);
	void setTileAt(int x,int y,bool val);


	void draw(SDL_Renderer * renderer);

	void loadMapImage(const char * imageName);

	void loadRoadFromFile(const char * fileName);

	void loadMapData(const char * fileName);

	int getNumberOfRoads();

	Road * getRoadAt(int index);
};

