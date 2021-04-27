#pragma once

#include "Game.hpp"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect sRect, SDL_Rect dRect);

	
};