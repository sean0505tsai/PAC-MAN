#include "stdafx.h"
#include "pinky.h"
#include <random>
#include <algorithm>

using namespace game_framework;
////////////////////////*initialize setting*////////////////////////
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
	loadWeakRES();
	loadCountRES();
}

void Pinky::reset() {
	leftX = 270;
	topY = 340;
	speed = 4;
	collision = true;
	currentState = SCATTER;
	direction = UP;
	nextDirection = DOWN;
	nextDirectionAvailable = false;
}

void Pinky::reborn() {
	leftX = 270;
	topY = 340;
	speed = 4;
	collision = true;
	direction = UP;
	currentState = SCATTER;
	nextDirection = RIGHT;
	nextDirectionAvailable = false;
	eatencount = 0;
	eaten = false;
	weakenstart = 0;
}

void Pinky::getEaten() {
	if (currentState = FRIGHTEN || currentState == COUNTDOWN) {
		if (eatencount == 0) {
			eatencount = 1;
			eaten = true;
		}
	}
}

int Pinky::getCurrentState() {
	return currentState;
}

/////////////////////////*ghost movement*////////////////////////
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

int Pinky::getDirectionIndex() {
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

int Pinky::reverseDirection() {
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

int Pinky::reverseIndex() {
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

void Pinky::onMove() {
	
	if (currentBlockType == 2) {
		if (leftX <= -16 || leftX >= 536) {
			teleport();
		}
	}
	//inside the start square
	if (currentBlockType == 3) {
		moveOutSquare();
	}
	else {

		if(nextDirectionAvailable && nextDirection != direction) {
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
			//change direction if need
			decideNextDirection();
		}
	}
}

bool Pinky::newDirectionAvailable(int newdirection) {
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

void Pinky::moveOutSquare() {
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

void Pinky::decideNextDirection() {

	//decide when needs to find another nextDirection
	//vector<int> directions = { UP, DOWN, LEFT, RIGHT };

	//find next direction
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);
	//if nextDirection equals to current direction then change the nextDirection
	if (nextDirection == direction) {
		while (newDirection == direction || newDirection == reverseDirection()) {
			newDirection = directions[dis(gen)];
		}
		//set the next direction
		setNextDirection(newDirection);
	}
	else if (collision == 1) {
		do {
			newDirection = directions[dis(gen)];
		} while ((!newDirectionAvailable(newDirection)) || newDirection == reverseDirection());
		setNextDirection(newDirection);
	}
}

void Pinky::setDirectionCollision(int flag, int direction) {
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


/////////////////////////*ghost animation*////////////////////////
void Pinky::onShow() {
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

void Pinky::frighten(int second) {
	currentState = FRIGHTEN;
	speed = 2;
	//record frightened mode start time(initialize)
	if (weakenstart == 0) {
		weakenstart = second;
	}
}

void Pinky::CountDown() {
	if (weakenstart != 0) {
		int period = timer - weakenstart;
		switch (period) {
		case 7:
			currentState = COUNTDOWN;
			break;
		case 10:
			currentState = SCATTER;
			speed = 4;
			weakenstart = 0;
			break;
		}
	}
}

void Pinky::setCurrentTime(int time) {
	timer = time;
}

void Pinky::loadUpRES() {
	movingUp.LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-up-1.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-up.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-up-1.bmp" }, RGB(0, 255, 0));
	movingUp.SetAnimation(60, false);
}

void Pinky::loadDownRES() {
	movingDown.LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-down-1.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-down.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-down-1.bmp" }, RGB(0, 255, 0));
	movingDown.SetAnimation(60, false);
}

void Pinky::loadLeftRES() {
	movingLeft.LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-left-1.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-left.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-left-1.bmp" }, RGB(0, 255, 0));
	movingLeft.SetAnimation(60, false);
}

void Pinky::loadRightRES() {
	movingRight.LoadBitmapByString({ "Resources/images/bmp/ghost/pinky/ghost-pinky-right-1.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-right.bmp",
									"Resources/images/bmp/ghost/pinky/ghost-pinky-right-1.bmp" }, RGB(0, 255, 0));
	movingRight.SetAnimation(60, false);
}

void Pinky::loadWeakRES() {
	weaking.LoadBitmapByString({ "Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-2.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp" }, RGB(0, 255, 0));
	weaking.SetAnimation(60, false);
}

void Pinky::loadCountRES() {
	//unfinished
	countdown.LoadBitmapByString({ "Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-4.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-2.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-3.bmp" }, RGB(0, 255, 0));
	countdown.SetAnimation(60, false);
}