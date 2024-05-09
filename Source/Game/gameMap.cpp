#include "stdafx.h"
#include "gameMap.h"
#include <string>

using namespace game_framework;

void GameMap::setMazeNo(int number) {
	mazeNo = number;
}

void GameMap::onInit() {
	// PacMan.onInit();
	mazeNo = 0;
	std::string filename = "Resources/images/bmp/maze/maze";
	LoadBitmapByString({ filename + std::to_string(mazeNo) + ".bmp" ,
							filename + std::to_string(mazeNo) + "-white.bmp" });
	ready.LoadBitmapByString({"Resources/images/bmp/ready.bmp"});
	SetTopLeft(0, 0);
	pointCount = 0;

	for (int i = 0; i < 3; i++) {
		life[i].LoadBitmapByString({ "Resources/images/bmp/pacman/pacman-open-left.bmp" }, RGB(255, 255, 255));
		life[i].SetTopLeft(20+50*i, 690);
	}

	readMazeMatrix();
	generateDots();
}

void GameMap::onShow() {
	ShowBitmap();
	for (int i = 0; i < 244; i++) {
		dots[i].ShowBitmap();
	}
	for (int i = 0; i < lifeCount; i++) {
		life[i].ShowBitmap();
	}
}

void GameMap::onMove(Character pacMan){
	for (int i = 0; i < 244; i++) {
		if (dots[i].isOverlap(pacMan.getX(), pacMan.getY())) { 
			if (!dots[i].isEaten()) pointCount++;
			dots[i].setEaten(true);
		}
	}

}

int GameMap::isCollision(int x, int y, int speed, int direction){
	//int yActual = y - 60;
	int xStart, xEnd, xTarget, yStart, yEnd, yTarget = 0;
	switch (direction) {
	case 0:		// UP ��
		xStart = x;
		xEnd = x + 20;
		yStart = y - 1;
		yEnd = yStart - speed;
		for (int i = yStart; i > yEnd; i--) {
			for (int j = xStart; j < xEnd; j++) {
				if (mapMatrix[i / 20][j / 20] != 0 && mapMatrix[i / 20][j / 20] != 2) {
					return y - i;		// �I���Z��
				}
			}
		}
		return 0;		// �L�I��

	case 1:		// DOWN ��
		xStart = x;
		xEnd = x + 20;
		yStart = y + 20;
		yEnd = yStart + speed;
		for (int i = yStart; i < yEnd; i++) {
			for (int j = xStart; j < xEnd; j++) {
				if (mapMatrix[i / 20][j / 20] != 0 && mapMatrix[i / 20][j / 20] != 2) {
					return i - (y + 19);		// �I���Z��
				}
			}
		}
		return 0;
	
	case 2:		// LEFT ��
		xStart = x - 1;
		xEnd = xStart - speed;
		yStart = y;
		yEnd = y + 20;
		xTarget = x - 1;
		for (int i = xStart; i > xEnd; i--) {
			for (int j = yStart; j < yEnd; j++) {
				if (mapMatrix[j / 20][i / 20] != 0 && mapMatrix[j / 20][i / 20] != 2) {
					return x - i;		// �I���Z��
				}
			}
		}
		return 0;
	
	case 3:		// RIGHT ��
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

bool GameMap::isLevelPass() {
	return (pointCount >= 244) ? true : false;
}

int GameMap::getCurrentScore() {
	return pointCount;
}

void GameMap::readMazeMatrix(){
	std::ifstream ifs("Resources/maze/maze" + std::to_string(mazeNo) + ".map");
	for (int i = 0; i < 34; i++) {
		for (int j = 0; j < 28; j++) {
			ifs >> mapMatrix[i][j];
		}
	}
	ifs.close();
}

void GameMap::generateDots(){
	for (int i = 0, k = 0; i < 34; i++) {
		for (int j = 0; j < 28; j++) {
			if (!((i >= 12 && i <= 22 && j >= 7 && j <= 20) || (i == 26 && (j == 13 || j == 14)))) {
				if (mapMatrix[i][j] == 0) {
					dots[k].onInit();
					if ((i == 5 && j == 1) || (i == 5 && j == 26) || (i == 26 && j == 1) || (i == 26 && j == 26)) {
						dots[k].setEnergizer(true);
						dots[k].SetTopLeft(j * 20 + 2, i * 20 + 2);
					}
					else {
						dots[k].SetTopLeft(j * 20 + 7, i * 20 + 7);
					}
					k++;
				}
			}
		}
	}
}

// ���o�����I�������
int GameMap::getBlockType(int x, int y) {
	return mapMatrix[(y+9)/20][(x+9)/20];
}