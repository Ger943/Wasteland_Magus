#pragma once
#include "Game.h"

class TextureManager{
public:
	static SDL_Texture* LoadTexture(const char* FileName, SDL_Renderer* Renderer);
};