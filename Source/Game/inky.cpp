#include "stdafx.h"
#include "inky.h"
#include <random>

using namespace game_framework;
////////////////////////*初始化設定*////////////////////////
void Inky::onInit() {
	/*
	leftX = 230;
	topY = 340;
	speed = 4;
	collision = true;
	direction = UP;
	nextDirection = DOWN;
	nextDirectionAvailable = false;
	*/
	reset();
	loadUpRES();
	loadDownRES();
	loadLeftRES();
	loadRightRES();
	loadWeakRES();
	loadCountRES();
}

void Inky::reset() {
	leftX = 230;
	topY = 340;
	speed = 4;
	collision = true;
	currentState = SCATTER;
	direction = UP;
	nextDirection = DOWN;
	nextDirectionAvailable = false;
}

/////////////////////////*鬼魂移動*////////////////////////
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

void Inky::moveOutSquare() {
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

int Inky::getDirectionIndex() {
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

int Inky::reverseDirection() {
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

int Inky::reverseIndex() {
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

void Inky::setCollision(int flag) {
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

void Inky::setDirectionCollision(int flag, int direction) {
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

bool Inky::newDirectionAvailable(int newdirection) {
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

void Inky::decideNextDirection() {

	//decide when needs to find another nextDirection
	//vector<int> directions = { UP, DOWN, LEFT, RIGHT };

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

void Inky::onMove() {

	if (currentBlockType == 2) {
		if (leftX <= -16 || leftX >= 536) {
			teleport();
		}
	}

	if (currentBlockType == 3) {
		moveOutSquare();
	}
	else {
		
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
}

void Inky::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
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

/////////////////////////*鬼魂動畫*////////////////////////
void Inky::onShow() {
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

void Inky::frighten(int second) {
	currentState = FRIGHTEN;
	//record frightened mode start time(initialize)
	if (weakenstart == 0) {
		weakenstart = second;
	}
}

void Inky::CountDown() {
	if (weakenstart != 0) {
		int period = currentTime - weakenstart;
		switch (period) {
		case 10:
			currentState = COUNTDOWN;
			break;
		case 15:
			currentState = SCATTER;
			weakenstart = 0;
			break;
		}
	}
}

void Inky::setCurrentTime(int time) {
	currentTime = time;
}

void Inky::loadUpRES() {
	movingUp.LoadBitmapByString({ "Resources/images/bmp/ghost/inky/ghost-inky-up-1.bmp",
									"Resources/images/bmp/ghost/inky/ghost-inky-up.bmp",
									"Resources/images/bmp/ghost/inky/ghost-inky-up-1.bmp" }, RGB(0, 255, 0));
	movingUp.SetAnimation(60, false);
}

void Inky::loadDownRES() {
	movingDown.LoadBitmapByString({ "Resources/images/bmp/ghost/inky/ghost-inky-down-1.bmp",
									"Resources/images/bmp/ghost/inky/ghost-inky-down.bmp",
									"Resources/images/bmp/ghost/inky/ghost-inky-down-1.bmp" }, RGB(0, 255, 0));
	movingDown.SetAnimation(60, false);
}

void Inky::loadLeftRES() {
	movingLeft.LoadBitmapByString({ "Resources/images/bmp/ghost/inky/ghost-inky-left-1.bmp",
									"Resources/images/bmp/ghost/inky/ghost-inky-left.bmp",
									"Resources/images/bmp/ghost/inky/ghost-inky-left-1.bmp" }, RGB(0, 255, 0));
	movingLeft.SetAnimation(60, false);
}

void Inky::loadRightRES() {
	movingRight.LoadBitmapByString({ "Resources/images/bmp/ghost/inky/ghost-inky-right-1.bmp",
									"Resources/images/bmp/ghost/inky/ghost-inky-right.bmp",
									"Resources/images/bmp/ghost/inky/ghost-inky-right-1.bmp" }, RGB(0, 255, 0));
	movingRight.SetAnimation(60, false);
}

void Inky::loadWeakRES() {
	///待修改	
	weaking.LoadBitmapByString({ "Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-2.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp" }, RGB(0, 0, 0));
	weaking.SetAnimation(60, false);
}

void Inky::loadCountRES() {
	//unfinished
	countdown.LoadBitmapByString({ "Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-4.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-2.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-3.bmp" }, RGB(0, 0, 0));
	countdown.SetAnimation(60, false);
}
