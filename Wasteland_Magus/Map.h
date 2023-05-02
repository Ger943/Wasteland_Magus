#pragma once
#include "Game.h"

class Map {
public:
	Map();
	~Map();
	void DrawMap();
	void LoadMap(int arr[20][25]);

private:
	SDL_Rect src, dest;
	SDL_Texture* dirtTexture;
	SDL_Texture* grassTexture;
	SDL_Texture* waterTexture;
	int mapArr[20][25];
};