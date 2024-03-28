#include "stdafx.h"
#include "gameMap.h"

using namespace game_framework;

void GameMap::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/board.bmp",
							"Resources/images/bmp/board-white.bmp" });
	SetTopLeft(0, 0);

	for (int i = 0; i < 3; i++) {
		life[i].LoadBitmapByString({ "Resources/images/bmp/pacman-open-left.bmp" }, RGB(255, 255, 255));
		life[i].SetTopLeft(20+50*i, 690);
	}
}

void GameMap::onShow() {
	ShowBitmap();
	for (int i = 0; i < lifeCount; i++) {
		life[i].ShowBitmap();
	}
}

int GameMap::isCollision(int x, int y){
	return mapMatrix[x/20][y/20];
}