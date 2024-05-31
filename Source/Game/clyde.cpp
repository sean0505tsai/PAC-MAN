#include "stdafx.h"
#include "clyde.h"
#include <random>

using namespace game_framework;

void Clyde::onInit() {
	//LoadBitmapByString({ "Resources/images/bmp/ghost/clyde/ghost-clyde-right.bmp" }, RGB(0, 0, 0));
	leftX = 310;
	//leftX = 120;
	topY = 340;
	speed = 4;
	collision = true;
	direction = LEFT;

	nextDirection = LEFT;
	nextDirectionAvailable = false;

	loadUpRES();
	loadDownRES();
	loadLeftRES();
	loadRightRES();
}

void Clyde::moveUp() {
	if (collision == 0) {
		topY -= speed;
	}
	else if (collision != 1) {
		topY -= (collision - 1);
	}
}

void Clyde::moveDown() {
	if (collision == 0) {
		topY += speed;
	}
	else if (collision != 1) {
		topY += (collision - 1);
	}
}

void Clyde::moveLeft() {
	if (collision == 0) {
		leftX -= speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Clyde::moveRight() {
	if (collision == 0) {
		leftX += speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Clyde::onMove() {

	if (nextDirectionAvailable && nextDirection != direction) {
		direction = nextDirection;
	}
	else {
		//sleep for couple seconds
		/*Direction to be automated by using function*/
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
		decideNextDirection();
	}
		
}

void Clyde::decideNextDirection() {
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


void Clyde::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	switch (direction) {
	case UP:
		movingUp.SetTopLeft(showX, showY);
		movingUp.SetAnimationPause(collision == 1 ? true : false);
		movingUp.ShowBitmap();
		break;
	case DOWN:
		movingDown.SetTopLeft(showX, showY);
		movingDown.SetAnimationPause(collision == 1 ? true : false);
		movingDown.ShowBitmap();
		break;
	case LEFT:
		movingLeft.SetTopLeft(showX, showY);
		movingLeft.SetAnimationPause(collision == 1 ? true : false);
		movingLeft.ShowBitmap();
		break;
	case RIGHT:
		movingRight.SetTopLeft(showX, showY);
		movingRight.SetAnimationPause(collision == 1 ? true : false);
		movingRight.ShowBitmap();
		break;
	}
	/*
	SetTopLeft(showX, showY);
	ShowBitmap();
	*/
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

void Clyde::loadUpRES() {
	movingUp.LoadBitmapByString({ "Resources/images/bmp/ghost/clyde/ghost-clyde-up-1.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-up.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-up-1.bmp" }, RGB(0, 0, 0));
	movingUp.SetAnimation(60, false);
}

void Clyde::loadDownRES() {
	movingDown.LoadBitmapByString({ "Resources/images/bmp/ghost/clyde/ghost-clyde-down-1.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-down.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-down-1.bmp" }, RGB(0, 0, 0));
	movingDown.SetAnimation(60, false);
}

void Clyde::loadLeftRES() {
	movingLeft.LoadBitmapByString({ "Resources/images/bmp/ghost/clyde/ghost-clyde-left-1.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-left.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-left-1.bmp" }, RGB(0, 0, 0));
	movingLeft.SetAnimation(60, false);
}

void Clyde::loadRightRES() {
	movingRight.LoadBitmapByString({ "Resources/images/bmp/ghost/clyde/ghost-clyde-right-1.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-right.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-right-1.bmp" }, RGB(0, 0, 0));
	movingRight.SetAnimation(60, false);
}