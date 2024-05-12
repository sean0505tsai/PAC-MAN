#include "stdafx.h"
#include "blinky.h"
#include <queue>
#include <vector>
#include <utility>
#include <stack>

using namespace game_framework;

void Blinky::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost-blinky-right.bmp" }, RGB(255, 255, 255));
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
	/*Direction priority up(0) > left(2) > down(1) > right(3)*/

void Blinky::onMove() {
	if (nextDirectionAvailable && nextDirection != direction) {
		direction = nextDirection;
	}
	else

		if (collision == 0) {

			switch (direction) {
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
			switch (direction) {
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

void Blinky::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	SetTopLeft(showX, showY);
	ShowBitmap();
}

void Blinky::findRoute(int targetX, int targetY) { //let ghost move to the target
	while (leftX != targetX && topY != targetY)
	{
		
	} 
}

void Blinky::scatterMove() {
	//I.紅鬼已進入繞圈軌道內
	if (leftX >= 420 && leftX <= 520 && topY <= 160 && topY >= 80) {
		//繞方形框框逆時針跑(420, 80)->(520, 160)

	}
	//II.紅鬼不在軌道範圍 
	else {
		//進入軌道起始點
		findRoute(420, 80);
	}
}

void Blinky::findPacman() {

}

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