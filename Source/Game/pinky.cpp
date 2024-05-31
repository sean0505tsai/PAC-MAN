#include "stdafx.h"
#include "pinky.h"
#include <random>
#include <algorithm>

using namespace game_framework;
////////////////////////*初始化設定*////////////////////////
void Pinky::onInit() {
	/*
	LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-right.bmp" }, RGB(0, 0, 0));
	leftX = 270;
	topY = 340;
	speed = 4;
	collision = true;
	direction = UP;
	nextDirection = LEFT;
	nextDirectionAvailable = false;
	*/
	reset();
	loadUpRES();
	loadDownRES();
	loadLeftRES();
	loadRightRES();
}

void Pinky::reset() {
	leftX = 270;
	topY = 340;
	speed = 4;
	collision = true;
	direction = UP;
	nextDirection = LEFT;
	nextDirectionAvailable = false;
}



/////////////////////////*鬼魂移動*////////////////////////
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

void Pinky::setCollision(int flag) {
	collision = flag;
	switch (direction) {
	case UP:
		upCollision = true ? collision != 1 : false;
		break;
	case DOWN:
		downCollision = true ? collision != 1 : false;
		break;
	case LEFT:
		leftCollision = true ? collision != 1 : false;
		break;
	case RIGHT:
		rightCollision = true ? collision != 1 : false;
		break;
	}
}

void Pinky::onMove() {


	//move the speicic position -> change direction
	if (nextDirectionAvailable && nextDirection != direction ) {
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

	}
}

void Pinky::leaveSquare() {
	if (leftX >= 268 && leftX <= 280) {
		direction = UP;
	}
	else if (leftX < 268) {
		direction = RIGHT;
	}
	else if (leftX > 280) {
		direction = LEFT;
	}

}







void Pinky::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
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


/////////////////////////*鬼魂動畫*////////////////////////
void Pinky::onShow() {
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

void Pinky::loadUpRES() {
	movingUp.LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-up-1.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-up.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-up-1.bmp" }, RGB(0, 0, 0));
	movingUp.SetAnimation(60, false);
}

void Pinky::loadDownRES() {
	movingDown.LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-down-1.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-down.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-down-1.bmp" }, RGB(0, 0, 0));
	movingDown.SetAnimation(60, false);
}

void Pinky::loadLeftRES() {
	movingLeft.LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-left-1.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-left.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-left-1.bmp" }, RGB(0, 0, 0));
	movingLeft.SetAnimation(60, false);
}

void Pinky::loadRightRES() {
	movingRight.LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-right-1.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-right.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-right-1.bmp" }, RGB(0, 0, 0));
	movingRight.SetAnimation(60, false);
}