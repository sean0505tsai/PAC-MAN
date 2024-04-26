#include "stdafx.h"
#include "pinky.h"

using namespace game_framework;

void Pinky::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost-pinky-right.bmp" }, RGB(255, 255, 255));
	leftX = 240;
	//leftX = 120;
	topY = 340;
	speed = 4;
	collision = true;
	direction = LEFT;

	nextDirection = LEFT;
	nextDirectionAvailable = false;
}

void Pinky::onMove() {

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

void Pinky::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	SetTopLeft(showX, showY);
	ShowBitmap();
}

void Pinky::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
}

void Pinky::setCollision(int flag) {
	collision = flag;
}

void Pinky::setMovingLeft(bool flag) {
	isMovingLeft = flag;
}

void Pinky::setMovingRight(bool flag) {
	isMovingRight = flag;
}

void Pinky::setMovingUp(bool flag) {
	isMovingUp = flag;
}

void Pinky::setMovingDown(bool flag) {
	isMovingDown = flag;
}

bool Pinky::getNextDirectionAVL() {
	return nextDirectionAvailable;
}