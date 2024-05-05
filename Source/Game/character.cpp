#include "stdafx.h"
#include "character.h"

using namespace game_framework;

void Character::onInit() {
	LoadBitmapByString({"Resources/images/bmp/pacman-open-left.bmp"}, RGB(255, 255, 255));
	movingUp.LoadBitmapByString({"Resources/images/bmp/"}, RGB(255, 255, 255));

	leftX = 270;
	topY = 520;
	speed = 4;
	collision = true;
	direction = LEFT;

	nextDirection = LEFT;
	nextDirectionAvailable = false;
}

void Character::onMove() {

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

void Character::setNextDirection(int inputDirection) {
	nextDirection = inputDirection;
}

void Character::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	SetTopLeft(showX, showY);
	ShowBitmap();
}

void Character::setCollision(int flag) {
	collision = flag;
}

void Character::setMovingLeft(bool flag) {
	isMovingLeft = flag;
}

void Character::setMovingRight(bool flag) {
	isMovingRight = flag;
}

void Character::setMovingUp(bool flag) {
	isMovingUp = flag;
}

void Character::setMovingDown(bool flag) {
	isMovingDown = flag;
}

bool Character::getNextDirectionAVL() {
	return nextDirectionAvailable;
}