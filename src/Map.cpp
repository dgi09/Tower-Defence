#include "Map.h"
#include "TextureLoader.h"
#include <fstream>



Map::Map(void)
{
	mapTexture = NULL;
	area.x = 0;
	area.y = 0;


	area.w = TILEWIDTH *  TILESX;
	area.h = TILEHEIGHT * TILESY;
}


Map::~Map(void)
{

}


bool Map::getTileAt(int x,int y)
{
	return tiles[y][x];
}

void Map::draw(SDL_Renderer * renderer)
{
	SDL_RenderCopy(renderer,mapTexture,NULL,&area);
}

void Map::loadMapImage(const char * imageName)
{
	int h,w;
	TextureLoader::getPtr()->loadTextureFromFile(imageName,&mapTexture,h,w);
}

// ------- ROAD --------

SDL_Point Road::getPointAt(int index)
{
	return roadTiles[index];
}

void Road::addRoadPoint(int x,int y)
{
	SDL_Point p;
	p.x = x;
	p.y =y ;
	roadTiles.push_back(p);
}

int Road::getRoadLenght()
{
	return roadTiles.size();
}

void Map::loadMapData(const char * fileName)
{
	std::ifstream file(fileName,std::ios::in);

	int x = 0;
	int y = 0;


	char c;
	while(file.eof() == false)
	{
		file.get(c);

		if(c != ',' && c != '\n')
		{
			if(c == '1')
			{
				tiles[x][y] = true;

			}
			else tiles[x][y] = false;

			y++;
		}

		if(c == '\n')
		{
			x++;
			y = 0;
		}
	}

	file.close();
}

int Map::getNumberOfRoads()
{
	return (int)roads.size();
}

Road * Map::getRoadAt(int index)
{
	if(index < getNumberOfRoads() && index >= 0)
		return &roads[index];
}

void Map::loadRoadFromFile(const char * fileName)
{
	std::ifstream file(fileName,std::ios::in);

	int numberOfTiles;
	int x,y;

	Road road;
	while(file.eof() == false)
	{
		file >> x;
		file >> y;

		road.addRoadPoint(x,y);
	}

	file.close();
	roads.push_back(road);


}

void Map::setTileAt(int x,int y,bool val)
{
	tiles[y][x] = val;
}
