#include "Game.h"
#include "TextureManager.h"

Game::Game() {}
Game::~Game() {}
SDL_Texture* playerTexture;
SDL_Rect srcR, dstR;
int charaSpeed = 8;

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


	playerTexture = TextureManager::LoadTexture("assets/player.png", renderer);
};

void Game::update() {

	dstR.h = 64;
	dstR.w = 64;

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
			dstR.x -= charaSpeed;
			std::cout << "Left button :" << std::endl;
			break;
		case SDLK_RIGHT:
			dstR.x += charaSpeed;
			break;
		case SDLK_UP:
			dstR.y -= charaSpeed;
			break;
		case SDLK_DOWN:
			dstR.y += charaSpeed;
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
	SDL_RenderCopy(renderer, playerTexture, NULL, &dstR);
	SDL_RenderPresent(renderer);
};