#include "stdafx.h"
#include "blinky.h"
#include <queue>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#include <stack>
#include <unordered_map>
/*
*/

using namespace game_framework;
////////////////////////*初始化設定*////////////////////////
void Blinky::onInit() {
	/*
	leftX = 268;
	topY = 280;
	speed = 4;
	collision = true;
	direction = RIGHT;
	nextDirection = UP;
	nextDirectionAvailable = false;
	*/
	reset();
	loadUpRES();
	loadDownRES();
	loadLeftRES();
	loadRightRES();
}

void Blinky::reset() {
	leftX = 268;
	topY = 280;
	speed = 4;
	collision = true;
	direction = RIGHT;
	nextDirection = UP;
	nextDirectionAvailable = false;
}

/////////////////////////*鬼魂移動*////////////////////////
void Blinky::moveUp() {
	if (collision == 0) {
			topY -= speed;
	}
	else if (collision != 1) {
			topY -= (collision - 1);
	}
}

void Blinky::moveDown() {
	if (collision == 0) {
		topY += speed;
	}
	else if (collision != 1) {
		topY += (collision - 1);
	}
}

void Blinky::moveLeft() {
	if (collision == 0) {
		leftX -= speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Blinky::moveRight() {
	if (collision == 0) {
		leftX += speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}


//convert current direction to int
int Blinky::getDirectionIndex() {
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

int Blinky::reverseDirection() {
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

int Blinky::reverseIndex() {
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

void Blinky::onMove() {

	if (currentBlockType == 2) {
		if (leftX <= -16 || leftX >= 536) {
			teleport();
		}
	}

	if (currentBlockType == 3) {
		moveOutSquare();
	}
	
	else {
	
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
			//determine the next direction
			decideNextDirection();
		}
	}
}

bool Blinky::newDirectionAvailable(int newdirection) {
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

void Blinky::moveOutSquare() {
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

//determine the next direction
void Blinky::decideNextDirection() {
	
	//decide when needs to find another nextDirection
	//vector<int> directions = { UP, DOWN, LEFT, RIGHT };

	//找尋下一方向
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);
	//if nextDirection equals to current direction then change the nextDirection
	if (nextDirection == direction ) {
		while (newDirection == direction || newDirection == reverseDirection()) {
			newDirection = directions[dis(gen)];
		}
		//設定下個方向
		setNextDirection(newDirection);
	}
	else if (collision == 1) {
		do {
			newDirection = directions[dis(gen)];
		} while ( (!newDirectionAvailable(newDirection)) || newDirection == reverseDirection());
		setNextDirection(newDirection);
	}
}

void Blinky::setDirectionCollision(int flag, int direction) {
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

	/*Direction priority up(0) > left(2) > down(1) > right(3)*/
/*void Blinky::findPacman() {

}*/

void Blinky::setNextDirection(int inputDirection) {
	nextDirection = inputDirection;
}

void Blinky::setCollision(int flag) {
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

void Blinky::setMovingLeft(bool flag) {
	isMovingLeft = flag;
}

void Blinky::setMovingRight(bool flag) {
	isMovingRight = flag;
}

void Blinky::setMovingUp(bool flag) {
	isMovingUp = flag;
}

void Blinky::setMovingDown(bool flag) {
	isMovingDown = flag;
}

bool Blinky::getNextDirectionAVL() {
	return nextDirectionAvailable;
}


/////////////////////////*鬼魂動畫*////////////////////////
void Blinky::onShow() {
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


void Blinky::loadUpRES() {
	movingUp.LoadBitmapByString({ "Resources/images/bmp/ghost/blinky/ghost-blinky-up-1.bmp",
									"Resources/images/bmp/ghost/blinky/ghost-blinky-up.bmp",
									"Resources/images/bmp/ghost/blinky/ghost-blinky-up-1.bmp" }, RGB(0, 0, 0));
	movingUp.SetAnimation(60, false);
}

void Blinky::loadDownRES() {
	movingDown.LoadBitmapByString({ "Resources/images/bmp/ghost/blinky/ghost-blinky-down-1.bmp",
									"Resources/images/bmp/ghost/blinky/ghost-blinky-down.bmp",
									"Resources/images/bmp/ghost/blinky/ghost-blinky-down-1.bmp" }, RGB(0, 0, 0));
	movingDown.SetAnimation(60, false);
}

void Blinky::loadLeftRES() {
	movingLeft.LoadBitmapByString({ "Resources/images/bmp/ghost/blinky/ghost-blinky-left-1.bmp",
									"Resources/images/bmp/ghost/blinky/ghost-blinky-left.bmp",
									"Resources/images/bmp/ghost/blinky/ghost-blinky-left-1.bmp" }, RGB(0, 0, 0));
	movingLeft.SetAnimation(60, false);
}

void Blinky::loadRightRES() {
	movingRight.LoadBitmapByString({ "Resources/images/bmp/ghost/blinky/ghost-blinky-right-1.bmp",
									"Resources/images/bmp/ghost/blinky/ghost-blinky-right.bmp",
									"Resources/images/bmp/ghost/blinky/ghost-blinky-right-1.bmp"}, RGB(0, 0, 0));
	movingRight.SetAnimation(60, false);
}

void Blinky::loadWeakRES() {
	///待修改	
	movingLeft.LoadBitmapByString({ "Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-2.bmp",
									"Resources/images/bmp/ghost/vulnerable/ghost-vulnerable-1.bmp"}, RGB(0, 0, 0));
	movingLeft.SetAnimation(60, false);
}