#pragma once 

#include "Game.hpp"

class GameObject
{
public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int xPos, yPos;

	SDL_Texture* objectTexture;
	SDL_Rect sRect, dRect;
};