#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName) {

	SDL_Surface* tempSurface = IMG_Load(fileName);
	printf("Error : %s", IMG_GetError());
	SDL_Texture* Texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	printf("Error : %s", IMG_GetError());
	SDL_FreeSurface(tempSurface);
	return Texture;
}
void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst){
	SDL_RenderCopy(Game::renderer, tex, &src, &dst);
};