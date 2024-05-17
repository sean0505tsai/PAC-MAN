#include "stdafx.h"
#include "clyde.h"

using namespace game_framework;

void Clyde::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost-clyde-right.bmp" }, RGB(255, 255, 255));
	leftX = 310;
	//leftX = 120;
	topY = 340;
	speed = 4;
	collision = true;
	direction = LEFT;

	nextDirection = LEFT;
	nextDirectionAvailable = false;
}

void Clyde::onMove() {

	if (nextDirectionAvailable && nextDirection != direction) {
		direction = nextDirection;
	}
	else
		/*Direction to be automated by using function*/
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

void Clyde::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	SetTopLeft(showX, showY);
	ShowBitmap();
}

void Clyde::normalMove() {
	
}

void Clyde::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
}

void Clyde::setCollision(int flag) {
	collision = flag;
}

void Clyde::setMovingLeft(bool flag) {
	isMovingLeft = flag;
}

void Clyde::setMovingRight(bool flag) {
	isMovingRight = flag;
}

void Clyde::setMovingUp(bool flag) {
	isMovingUp = flag;
}

void Clyde::setMovingDown(bool flag) {
	isMovingDown = flag;
}

bool Clyde::getNextDirectionAVL() {
	return nextDirectionAvailable;
}