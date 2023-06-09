#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Game {
public:
	Game();
	~Game();
	void init(const char* title, int w_posx, int w_posy, int w_width, int w_height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	static SDL_Renderer* renderer;

	bool running() {
		return isRunning;
	}


private:
	bool isRunning;
	SDL_Window* window;
};

#endif // !Game.hpp
#pragma once
