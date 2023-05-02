#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* textureSheet, int initX, int initY);
	~GameObject();
	void Update();
	void Render();
	void XMove(int dir);
	void YMove(int dir);
private:
	int xPos;
	int yPos;
	int charaSpeed;
	SDL_Texture* objectTexture;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	SDL_Renderer* render;
};
