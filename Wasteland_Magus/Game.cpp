#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include <random>

Game::Game() {}
Game::~Game() {}
SDL_Texture* playerTexture;
SDL_Rect srcR, dstR;
int charaSpeed = 8;
GameObject* player;
GameObject* orc;

void Game::init(const char* title, int w_posx, int w_posy, int w_width, int w_height, bool fullscreen) {

	int flags = 0;

	if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialized ... " << std::endl;

		window = SDL_CreateWindow(title, w_posx, w_posy, w_width, w_height, flags);
		if (window) {
			std::cout << "Window successfully created ..." << std::endl;
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer) {
				SDL_SetRenderDrawColor(renderer, 12, 20, 12, 20);
				std::cout << "Renderer successfully created ..." << std::endl;
				isRunning = true;
			}
		}
	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/player.png", renderer,0,0);
	orc = new GameObject("assets/orc.png", renderer,16,240);
};

void Game::update() {
	player->Update();
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(-1, 1);
	orc->XMove(distr(gen));
	orc->YMove(distr(gen));
	orc->Update();
	
};
void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			player->XMove(-1);
			break;
		case SDLK_RIGHT:
			player->XMove(1);
			break;
		case SDLK_UP:
			player->YMove(-1);
			break;
		case SDLK_DOWN:
			player->YMove(1);
			break;
		default:
			break;
		}
	default:
		break;
	}
};
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
};
void Game::render() {
	SDL_RenderClear(renderer);
	// Textures to render here , farthest first
	player->Render();
	orc->Render();
	SDL_RenderPresent(renderer);
};