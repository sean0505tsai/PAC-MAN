#include "stdafx.h"
#include "pinky.h"
#include <random>

using namespace game_framework;

void Pinky::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-right.bmp" }, RGB(0, 0, 0));
	leftX = 230;
	//leftX = 120;
	topY = 340;
	speed = 4;
	collision = true;
	direction = LEFT;

	nextDirection = LEFT;
	nextDirectionAvailable = false;
}

void Pinky::onMove() {

	//move the speicic position -> change direction
	if (nextDirectionAvailable && nextDirection != direction && collision != 1) {
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
		//determine the next direction
		decideNextDirection();

	}
}

void Pinky::moveUp() {
	if (collision == 0) {
		topY -= speed;
	}
	else if (collision != 1) {
		topY -= (collision - 1);
	}
}

void Pinky::moveDown() {
	if (collision == 0) {
		topY += speed;
	}
	else if (collision != 1) {
		topY += (collision - 1);
	}
}

void Pinky::moveLeft() {
	if (collision == 0) {
		leftX -= speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Pinky::moveRight() {
	if (collision == 0) {
		leftX += speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Pinky::decideNextDirection() {

	//decide when needs to find another nextDirection
	vector<int> directions = { UP, DOWN, LEFT, RIGHT };

	//找尋下一方向
	int newDirection;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);
	//if nextDirection equals to current direction then change the nextDirection
	if (nextDirection == direction || collision == 1) {
		while (newDirection == direction) {
			newDirection = directions[dis(gen)];
		}
		//設定下個方向
		setNextDirection(newDirection);
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