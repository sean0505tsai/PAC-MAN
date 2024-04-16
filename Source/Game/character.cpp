#include "stdafx.h"
#include "character.h"

using namespace game_framework;

void Character::onInit() {
	LoadBitmapByString({"Resources/images/bmp/pacman-open-left.bmp"}, RGB(255, 255, 255));
	//leftX = 270;
	leftX = 120;
	//topY = 520;
	topY = 520;
	speed = 5;
	collision = true;
	direction = UP;

	/*
	isMovingUp = false;
	isMovingDown = false;
	isMovingLeft = false;
	isMovingRight = false;
	*/
	nextDirection = UP;
	nextDirectionAvailable = false;
}

void Character::onMove() {
	
	if (nextDirectionAvailable && nextDirection != direction) {
		direction = nextDirection;
		// nextDirection = NULL;
		//collision = false;
	}else
	if (collision == 0) {
		if(direction == UP) topY -= speed;
		if(direction == DOWN) topY += speed;
		if(direction == LEFT) leftX -= speed;
		if(direction == RIGHT) leftX += speed;
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