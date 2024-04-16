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
		yStart = y - 1;
		yEnd = yStart - speed;
		for (int i = yStart; i > yEnd; i--) {
			for (int j = xStart; j < xEnd; j++) {
				if (mapMatrix[i / 20][j / 20] != 0 && mapMatrix[i / 20][j / 20] != 2) {
					return y - i;		// ¸I¼²¶ZÂ÷
				}
			}
		}
		return 0;		// µL¸I¼²

	case 1:		// DOWN ¡õ
		xStart = x;
		xEnd = x + 20;
		yStart = y + 20;
		yEnd = yStart + speed;
		for (int i = yStart; i < yEnd; i++) {
			for (int j = xStart; j < xEnd; j++) {
				if (mapMatrix[i / 20][j / 20] != 0 && mapMatrix[i / 20][j / 20] != 2) {
					return i - (y + 19);		// ¸I¼²¶ZÂ÷
				}
			}
		}
		return 0;
	
	case 2:		// LEFT ¡ö
		xStart = x - 1;
		xEnd = xStart - speed;
		yStart = y;
		yEnd = y + 20;
		xTarget = x - 1;
		for (int i = xStart; i > xEnd; i--) {
			for (int j = yStart; j < yEnd; j++) {
				if (mapMatrix[j / 20][i / 20] != 0 && mapMatrix[j / 20][i / 20] != 2) {
					return x - i;		// ¸I¼²¶ZÂ÷
				}
			}
		}
		return 0;
	
	case 3:		// RIGHT ¡÷
		xStart = x + 20;
		xEnd = xStart + speed;
		yStart = y;
		yEnd = y + 20;
		for (int i = xStart; i < xEnd; i++) {
			for (int j = yStart; j < yEnd; j++) {
				if (mapMatrix[j / 20][i / 20] != 0 && mapMatrix[j / 20][i / 20] != 2) {
					return i - (x + 19);
				}
			}
		}
		return 0;
	}
	return 1;
}