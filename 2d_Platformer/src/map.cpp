#include "Map.hpp"


int lvl1[20][25] = 
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,2,2,2,2,2},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,1}
};

Map::Map()
{
	air = TextureManager::LoadTexture("res/img/air.png");
	dirt = TextureManager::LoadTexture("res/img/dirt.png");
	grass = TextureManager::LoadTexture("res/img/grass.png");
	water = TextureManager::LoadTexture("res/img/water.png");

	LoadMap(lvl1);

	sRect.x = sRect.y = 0;
	sRect.w = dRect.w = 32;
	sRect.h = dRect.h = 32;

	dRect.x = dRect.y = 0;
}

void Map::LoadMap(int arr[20][25])	
{
	for (int row = 0; row < 20; ++row)
	{
		for (int col = 0; col < 25; ++col)
		{
			map[row][col] = arr[row][col];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;


	for (int row = 0; row < 20; ++row)
	{
		for (int col = 0; col < 25; ++col)
		{
			type = map[row][col];

			dRect.x = col * 32;
			dRect.y = row * 32;

			switch(type)
			{
				case 0:
					TextureManager::Draw(air, sRect, dRect);
					break;
				case 1:
					TextureManager::Draw(dirt, sRect, dRect);
					break;
				case 2:
					TextureManager::Draw(grass, sRect, dRect);
					break;
				case 3:
					TextureManager::Draw(water, sRect, dRect);
					break;
					
				default:
					break;			

			}
		}
	}
}