#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objectTexture = TextureManager::LoadTexture(textureSheet);

	xPos = x;
	yPos = y;
}

void GameObject::Update()
{
	xPos++;
	yPos++;

	sRect.h = 29;
	sRect.w = 16;
	sRect.x = 0;
	sRect.y = 0;

	dRect.h = sRect.h * 2;	
	dRect.w = sRect.w * 2;
	dRect.x = xPos;
	dRect.y = yPos;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objectTexture, &sRect, &dRect);
}