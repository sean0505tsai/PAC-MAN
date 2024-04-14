#include "stdafx.h"
#include "character.h"

using namespace game_framework;

void Character::onInit() {
	LoadBitmapByString({"Resources/images/bmp/pacman-open-left.bmp"}, RGB(255, 255, 255));
	leftX = 270;
	topY = 520;
	speed = 2;
	collision = false;
	direction = LEFT;

	/*
	isMovingUp = false;
	isMovingDown = false;
	isMovingLeft = false;
	isMovingRight = false;
	*/
	nextDirection = LEFT;
	nextDirectionAvailable = false;
}

void Character::onMove() {
	
	if (nextDirectionAvailable && direction != nextDirection) {
		direction = nextDirection;
		// nextDirection = NULL;
		collision = false;
	}
	else if (!collision) {
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
	
	/*
	if (isMovingLeft) leftX -= speed;
	if (isMovingRight) leftX += speed;
	if (isMovingUp) topY -= speed;
	if (isMovingDown) topY += speed;
	*/
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

void Character::setCollision(bool flag) {
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