#include "stdafx.h"
#include "blinky.h"
#include "../Game/gameMap.h"
#include <queue>
#include <vector>
#include <utility>
#include <stack>
//#include <unordered_map>

using namespace game_framework;

void Blinky::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost/blinky/ghost-blinky-right.bmp" }, RGB(0, 0, 0));
	leftX = 270;
	//leftX = 120;
	topY = 280;
	speed = 4;
	collision = true;
	direction = RIGHT;
	state currentState = SCATTER;

	nextDirection = UP;
	nextDirectionAvailable = false;
}

void Blinky::setCurrentBlockType(int Type) {
	currentBlockType = Type;
}

void Blinky::onMove() {
	if (nextDirectionAvailable && nextDirection != direction) {
		direction = nextDirection;
	}
	else {
		switch (direction) {
		case UP:
			moveUp();
			break;
		case DOWN:
			moveDown();
			break;
		case LEFT:
			moveLeft();
			break;
		case RIGHT:
			moveRight();
			break;
		}
	}
}

/*
vector<std::pair<int, int>> Blinky::findShortestPath(int targetX, int targetY) {
	
	
}
*/
void Blinky::updateNextDirection(int targetX, int targetY) {

}

void Blinky::moveUp() {
	if (collision == 0) {
			topY -= speed;
	}
	else if (collision != 1) {
			topY -= (collision - 1);
	}
}

void Blinky::moveDown() {
	if (collision == 0) {
		topY += speed;
	}
	else if (collision != 1) {
		topY += (collision - 1);
	}
}

void Blinky::moveLeft() {
	if (collision == 0) {
		leftX -= speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Blinky::moveRight() {
	if (collision == 0) {
		leftX += speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Blinky::moveByDirection(int moveDirection) {
	if (collision == 0) {

		switch (moveDirection) {
		case UP:
			topY -= speed;
			break;
		case DOWN:
			topY += speed;
			break;
		case LEFT:
			leftX -= speed;
			break;
		case RIGHT:
			leftX += speed;
			break;
		}

	}
	else if (collision != 1) {
		switch (moveDirection) {
		case UP:
			topY -= (collision - 1);
			break;
		case DOWN:
			topY += (collision - 1);
			break;
		case LEFT:
			leftX -= (collision - 1);
			break;
		case RIGHT:
			leftX += (collision - 1);
			break;
		}
	}
}
	/*Direction priority up(0) > left(2) > down(1) > right(3)*/

void Blinky::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	SetTopLeft(showX, showY);
	ShowBitmap();
}

/*void Blinky::findRoute(int targetX, int targetY) { //let ghost move to the target
	while (leftX != targetX && topY != targetY)
	{
		
	} 
}*/

/*void Blinky::findPacman() {

}*/

void Blinky::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
}

void Blinky::setCollision(int flag) {
	collision = flag;
}

void Blinky::setMovingLeft(bool flag) {
	isMovingLeft = flag;
}

void Blinky::setMovingRight(bool flag) {
	isMovingRight = flag;
}

void Blinky::setMovingUp(bool flag) {
	isMovingUp = flag;
}

void Blinky::setMovingDown(bool flag) {
	isMovingDown = flag;
}

bool Blinky::getNextDirectionAVL() {
	return nextDirectionAvailable;
}