#include "stdafx.h"
#include "inky.h"
#include <random>

using namespace game_framework;

void Inky::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost/inky/ghost-inky-right.bmp" }, RGB(0, 0, 0));
	leftX = 270;
	//leftX = 120;
	topY = 340;
	speed = 4;
	collision = true;
	direction = UP;

	nextDirection = LEFT;
	nextDirectionAvailable = false;
}

void Inky::onMove() {

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
		//determine the next direction
		decideNextDirection();

	}
}

void Inky::moveUp() {
	if (collision == 0) {
		topY -= speed;
	}
	else if (collision != 1) {
		topY -= (collision - 1);
	}
}

void Inky::moveDown() {
	if (collision == 0) {
		topY += speed;
	}
	else if (collision != 1) {
		topY += (collision - 1);
	}
}

void Inky::moveLeft() {
	if (collision == 0) {
		leftX -= speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Inky::moveRight() {
	if (collision == 0) {
		leftX += speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Inky::decideNextDirection() {
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