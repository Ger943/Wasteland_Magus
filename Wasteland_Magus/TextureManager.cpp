#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* renderer) {

	SDL_Surface* tempSurface = IMG_Load(fileName);
	printf("Error : %s", IMG_GetError());
	SDL_Texture* Texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	printf("Error : %s", IMG_GetError());
	SDL_FreeSurface(tempSurface);
	return Texture;
};