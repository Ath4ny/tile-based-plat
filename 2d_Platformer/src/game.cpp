#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{};
Game::~Game()
{};

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!..." << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

		if(window)
		{
			std::cout << "Window created!..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if(renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!..." << std::endl;
		}

		isRunning = true;

	} 
	else
	{
		isRunning = false;
	}

	player = new GameObject("res/img/ninja-idle.png", 0, 0);
	enemy = new GameObject("res/img/adventurer-idle.png", 50, 50);
	map = new Map();

};

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;

		default: 
			break;
	}
};

void Game::update()
{
	player->Update();
	enemy->Update();
};

void Game::render()
{
	SDL_RenderClear(renderer);
	//STUFF TO RENDER
	map->DrawMap();
	player->Render();
	enemy->Render();
	//STUFF TO RENDER 
	SDL_RenderPresent(renderer);
};

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game cleaned up!" << std::endl;
};

