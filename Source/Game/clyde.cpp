#include "stdafx.h"
#include "clyde.h"
#include <random>

using namespace game_framework;
////////////////////////*初始化設定*////////////////////////
void Clyde::onInit() {

	reset();
	loadUpRES();
	loadDownRES();
	loadLeftRES();
	loadRightRES();
	loadWeakRES();
	loadCountRES();
}

void Clyde::reset() {
	leftX = 310;
	topY = 340;
	speed = 4;
	collision = true;
	currentState = SCATTER;
	direction = UP;
	nextDirection = DOWN;
	nextDirectionAvailable = false;
	weakenStart = 0;
}
////////////////////////*鬼魂移動*////////////////////////
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

void Clyde::moveOutSquare() {

	if (leftX >= 268 && leftX <= 278) {
		topY -= speed;
	}
	else if (leftX < 268) {
		leftX += speed;
	}
	else if (leftX > 278) {
		leftX -= speed;
	}
}

int Clyde::getDirectionIndex() {
	switch (direction) {
	case UP:
		return 0;
		break;
	case DOWN:
		return 1;
		break;
	case LEFT:
		return 2;
		break;
	case RIGHT:
		return 3;
		break;
	}
}

int Clyde::reverseDirection() {
	switch (direction) {
	case UP:
		return DOWN;
		break;
	case DOWN:
		return UP;
		break;
	case LEFT:
		return RIGHT;
		break;
	case RIGHT:
		return LEFT;
		break;
	}
}

int Clyde::reverseIndex() {
	switch (direction) {
	case UP:
		return 1;
		break;
	case DOWN:
		return 0;
		break;
	case LEFT:
		return 3;
		break;
	case RIGHT:
		return 2;
		break;
	}
}

void Clyde::setCollision(int flag) {
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

void Clyde::setDirectionCollision(int flag, int direction) {
	switch (direction) {
	case 0:
		upCollision = true ? flag != 1 : false;
		break;
	case 1:
		downCollision = true ? flag != 1 : false;
		break;
	case 2:
		leftCollision = true ? flag != 1 : false;
		break;
	case 3:
		rightCollision = true ? flag != 1 : false;
		break;
	}
}

bool Clyde::newDirectionAvailable(int newdirection) {
	switch (newdirection) {
	case UP:
		return upCollision;
		break;
	case DOWN:
		return downCollision;
		break;
	case LEFT:
		return leftCollision;
		break;
	case RIGHT:
		return rightCollision;
		break;
	}
}

void Clyde::onMove() {

	//通道
	if (currentBlockType == 2) {
		speed = 2;
		if (leftX <= -16 || leftX >= 536) {
			teleport();
		}
	}
	else if (currentState == SCATTER || currentState == CHASE) speed = 4;

	if (currentBlockType == 3) {
		moveOutSquare();
	}
	else {
		
		if (nextDirectionAvailable && nextDirection != direction) {
			direction = nextDirection;
		}
		else {
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
}

void Clyde::decideNextDirection() {
	//找尋下一方向
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);
	//if nextDirection equals to current direction then change the nextDirection
	if (nextDirection == direction) {
		while (newDirection == direction || newDirection == reverseDirection()) {
			newDirection = directions[dis(gen)];
		}
		//設定下個方向
		setNextDirection(newDirection);
	}
	else if (collision == 1) {
		do {
			newDirection = directions[dis(gen)];
		} while ((!newDirectionAvailable(newDirection)) || newDirection == reverseDirection());
		setNextDirection(newDirection);
	}
}

void Clyde::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
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

////////////////////////*鬼魂動畫*////////////////////////
void Clyde::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	switch (currentState) {
	case SCATTER:
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
		break;
	case FRIGHTEN:
		weaking.SetTopLeft(showX, showY);
		weaking.SetAnimationPause(collision == 1 ? true : false);
		weaking.ShowBitmap();
		break;
	case COUNTDOWN:
		countdown.SetTopLeft(showX, showY);
		countdown.SetAnimationPause(collision == 1 ? true : false);
		countdown.ShowBitmap();
		break;
	}
	/*
	SetTopLeft(showX, showY);
	ShowBitmap();
	*/
}

void Clyde::loadUpRES() {
	movingUp.LoadBitmapByString({ "Resources/images/bmp/ghost/clyde/ghost-clyde-up-1.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-up.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-up-1.bmp" }, RGB(0, 255, 0));
	movingUp.SetAnimation(60, false);
}

void Clyde::loadDownRES() {
	movingDown.LoadBitmapByString({ "Resources/images/bmp/ghost/clyde/ghost-clyde-down-1.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-down.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-down-1.bmp" }, RGB(0, 255, 0));
	movingDown.SetAnimation(60, false);
}

void Clyde::loadLeftRES() {
	movingLeft.LoadBitmapByString({ "Resources/images/bmp/ghost/clyde/ghost-clyde-left-1.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-left.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-left-1.bmp" }, RGB(0, 255, 0));
	movingLeft.SetAnimation(60, false);
}

void Clyde::loadRightRES() {
	movingRight.LoadBitmapByString({ "Resources/images/bmp/ghost/clyde/ghost-clyde-right-1.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-right.bmp",
									"Resources/images/bmp/ghost/clyde/ghost-clyde-right-1.bmp" }, RGB(0, 255, 0));
	movingRight.SetAnimation(60, false);
}

void Clyde::loadWeakRES() {
	///待修改	
	weaking.LoadBitmapByString({ "Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-2.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp" }, RGB(0, 255, 0));
	weaking.SetAnimation(60, false);
}

void Clyde::loadCountRES() {
	//unfinished
	countdown.LoadBitmapByString({ "Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-4.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-2.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-3.bmp" }, RGB(0, 255, 0));
	countdown.SetAnimation(60, false);
}