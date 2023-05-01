#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer, int initX, int initY) {
	render = renderer;
	objectTexture = TextureManager::LoadTexture(textureSheet, renderer);

	xPos = initX;
	yPos = initY;
	charaSpeed = 8;

	srcRect.w = 64;
	srcRect.h = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.w = 64;
	dstRect.h = 64;
	dstRect.x = xPos;
	dstRect.y = yPos;

};

void GameObject::Update() {

	dstRect.x = xPos;
	dstRect.y = yPos;

}

void GameObject::XMove(int dir) { xPos += dir * charaSpeed; }
void GameObject::YMove(int dir) { yPos += dir * charaSpeed; }

void GameObject::Render() {

	SDL_RenderCopy(render, objectTexture, &srcRect, &dstRect);
}