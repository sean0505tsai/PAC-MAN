#include "stdafx.h"
#include "inky.h"

using namespace game_framework;

void Inky::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost-inky-right.bmp" }, RGB(255, 255, 255));
	leftX = 270;
	//leftX = 120;
	topY = 340;
	speed = 4;
	collision = true;
	direction = LEFT;

	nextDirection = LEFT;
	nextDirectionAvailable = false;
}

void Inky::onMove() {

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

void Inky::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	SetTopLeft(showX, showY);
	ShowBitmap();
}

void Inky::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
}

void Inky::setCollision(int flag) {
	collision = flag;
}

void Inky::setMovingLeft(bool flag) {
	isMovingLeft = flag;
}

void Inky::setMovingRight(bool flag) {
	isMovingRight = flag;
}

void Inky::setMovingUp(bool flag) {
	isMovingUp = flag;
}

void Inky::setMovingDown(bool flag) {
	isMovingDown = flag;
}

bool Inky::getNextDirectionAVL() {
	return nextDirectionAvailable;
}