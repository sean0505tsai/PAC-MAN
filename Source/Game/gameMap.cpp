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

int GameMap::isCollision(int x, int y, int speed, int direction){
	//int yActual = y - 60;
	int xStart, xEnd, xTarget, yStart, yEnd, yTarget = 0;
	switch (direction) {
	case 0:		// UP ¡ô
		xStart = x;
		xEnd = x + 20;
		yTarget = y - 1;
		for (int i = xStart; i < xEnd; i++) {
			if (mapMatrix[yTarget / 20][i / 20] != 0) return 1;
		}
		return 0;		// µL¸I¼²

	case 1:		// DOWN ¡õ
		xStart = x;
		xEnd = x + 20;
		yTarget = y + 20;
		for (int i = xStart; i < xEnd; i++) {
			if (mapMatrix[yTarget / 20][i / 20] != 0) return 1;
		}
		return 0;
	
	case 2:		// LEFT ¡ö
		yStart = y;
		yEnd = y + 20;
		xTarget = x - 1;
		for (int i = yStart; i < yEnd; i++) {
			if (mapMatrix[i / 20][xTarget / 20] != 0) return 1;
		}
		return 0;
	
	case 3:		// RIGHT ¡÷
		yStart = y;
		yEnd = y + 20;
		xTarget = x + 20;
		for (int i = yStart; i < yEnd; i++) {
			if (mapMatrix[i / 20][xTarget / 20] != 0) return 1;
		}
		return 0;
	}
	return 0;
}