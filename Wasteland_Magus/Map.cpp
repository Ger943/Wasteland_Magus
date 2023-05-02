#include "Map.h"
#include "TextureManager.h"
#include "iostream"

//default temporary level 
// oh God , I feel like a heretic to do this 
int lvl1[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,2,2,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,2,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,2,2,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,2,2,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}
};

Map::Map() { 
	waterTexture = TextureManager::LoadTexture("assets/water.png");		// represented by 0 in the array...
	grassTexture = TextureManager::LoadTexture("assets/grass.png");		// .. by 1 ... 
	dirtTexture = TextureManager::LoadTexture("assets/dirt.png");		// ... and by 2.
	LoadMap(lvl1);														// LoadMap with default defined here
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;
}
Map::~Map() {

}
void Map::LoadMap(int arr[20][25]) {
	
	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 25; col++) {
			mapArr[row][col] = arr[row][col];
		}
	}

}
void Map::DrawMap() {
	int type = 0;

	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 25; col++) {
			type = mapArr[row][col];
			dest.x = col * dest.w;
			dest.y = row * dest.h;

			switch (type) {
			case 0:
				TextureManager::Draw(waterTexture, src, dest);
				break;
			case 1:
				TextureManager::Draw(grassTexture, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirtTexture, src, dest);
				break;
			default:
				break;
			}

			// std::cout << type;
		}
	}
}