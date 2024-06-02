#include "stdafx.h"
#include "gameMap.h"
#include <string>

using namespace game_framework;

GameMap::GameMap() {

}

GameMap::GameMap(int number) {
	mazeNo = number;
}

void GameMap::setMazeNo(int number) {
	//mazeNo = number;
	loadMazeRES();
	readMazeMatrix();
}

void GameMap::onInit() {

	ready.LoadBitmapByString({"Resources/images/bmp/ready.bmp"});
	ready.SetTopLeft(205, 400);
	SetTopLeft(0, 0);
	
	stage = READY;
	timer = 0;
	timeStart = GetTickCount();
}

void GameMap::onShow() {
	ShowBitmap();
	if(stage == READY) ready.ShowBitmap();
}

void GameMap::onMove(){
	updateTimer();
	if (timer > 3) stage = RUNNING;
}

void GameMap::togglePassAnimation(){
}


int GameMap::isCollision(int x, int y, int speed, int direction){
	//int yActual = y - 60;
	int xStart, xEnd, xTarget, yStart, yEnd, yTarget = 0;
	switch (direction) {
	case 0:		// UP
		xStart = x;
		xEnd = x + 20;
		yStart = y - 1;
		yEnd = yStart - speed;
		for (int i = yStart; i > yEnd; i--) {
			for (int j = xStart; j < xEnd; j++) {
				if (mapMatrix[i / 20][j / 20] != 0 && mapMatrix[i / 20][j / 20] != 2) {
					return y - i;		// collide distance
				}
			}
		}
		return 0;		// no collision

	case 1:		// DOWN
		xStart = x;
		xEnd = x + 20;
		yStart = y + 20;
		yEnd = yStart + speed;
		for (int i = yStart; i < yEnd; i++) {
			for (int j = xStart; j < xEnd; j++) {
				if (mapMatrix[i / 20][j / 20] != 0 && mapMatrix[i / 20][j / 20] != 2) {
					return i - (y + 19);		// collide distance
				}
			}
		}
		return 0;
	
	case 2:		// LEFT
		xStart = x - 1;
		xEnd = xStart - speed;
		yStart = y;
		yEnd = y + 20;
		xTarget = x - 1;
		for (int i = xStart; i > xEnd; i--) {
			for (int j = yStart; j < yEnd; j++) {
				if (mapMatrix[j / 20][i / 20] != 0 && mapMatrix[j / 20][i / 20] != 2) {
					return x - i;		// collide distance
				}
			}
		}
		return 0;
	
	case 3:		// RIGHT
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

int GameMap::getCurrentStage(){
	return stage;
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

void GameMap::loadMazeRES() {
	std::string filename = "Resources/images/bmp/maze/maze";
	LoadBitmapByString({ filename + std::to_string(mazeNo) + ".bmp" ,
							filename + std::to_string(mazeNo) + "-white.bmp" });
}

// get block type of certain coordinate
int GameMap::getBlockType(int x, int y) {
	return mapMatrix[(y+9)/20][(x+9)/20];
}

int GameMap::getBlockTypeByIndex(int row, int column){
	return mapMatrix[row][column];
}

// get map timer
int GameMap::getTimerCount(){
	return timer;
}

void GameMap::updateTimer() {
	DWORD end = GetTickCount();
	if (end - timeStart >= 1000) {	// 1000ms = 1sec
		timer++;
		timeStart = GetTickCount();		// update timer
	}
}