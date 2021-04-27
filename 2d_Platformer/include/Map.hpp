#pragma once
#include "TextureManager.hpp"
#include "Game.hpp"

class Map
{
public:
	Map();
	~Map();
	
	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	SDL_Rect sRect, dRect;

	SDL_Texture* air;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};