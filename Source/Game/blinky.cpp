#include "stdafx.h"
#include "blinky.h"
#include <queue>
#include <vector>
#include <utility>
#include <stack>
#include <unordered_map>
#include <random>
#include <algorithm>

using namespace game_framework;

void Blinky::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost-blinky-right.bmp" }, RGB(255, 255, 255));
	leftX = 270;
	topY = 280;
	speed = 4;
	collision = true;
	direction = RIGHT;
	//state currentState = SCATTER;

	nextDirection = UP;
	nextDirectionAvailable = false;
}

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

void Blinky::setCurrentBlockType(int Type) {
	currentBlockType = Type;
}

//convert current direction to int
void Blinky::setDirectionIndex() {
	switch (direction) {
	case UP:
		directionIndex = 0;
		break;
	case DOWN:
		directionIndex = 1;
		break;
	case LEFT:
		directionIndex = 2;
		break;
	case RIGHT:
		directionIndex = 3;
		break;
	}
}

void Blinky::onMove() {
	//(Randomly) choose the next direction
	//int availableDirection = 0;
	/*
	bool variables[] = { upAvailable, downAvailable, leftAvailable, rightAvailable };
	vector<int> trueIndex;
	setDirectionIndex();
	for (int i = 0; i < 4;i++) {
		if (variables[i] && i != directionIndex ) {
			//++availableDirection;
			trueIndex.push_back(i);
		}
	}
	//沒有方向可轉就不做任何事
	if (trueIndex.size() != 0) {
		if (trueIndex.size() == 1) {
			setNextDirection(trueIndex.at(0));
		}
		else if (trueIndex.size() > 1) {
			//remove the current direction
			//choose next direction randomly
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> dis(0, trueIndex.size() - 1);
			//set the next direction
			setNextDirection(dis(gen));
		}
	
	}
	*/

	
	//move the speicic position -> change direction
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
			//determine the next direction
			
		}
	}

}

//determine the next direction
void Blinky::decideNextDirection() {
	//檢查當前方向能否移動
	if (collision != 1) {
		return;
	}
	//找尋下一方向

	//設定下個方向

}



void Blinky::scatterMove() {
	/*
	while (true) {

	}
	*/
}
	/*Direction priority up(0) > left(2) > down(1) > right(3)*/

void Blinky::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	SetTopLeft(showX, showY);
	ShowBitmap();
}


/*void Blinky::findPacman() {

}*/

void Blinky::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
}

void Blinky::setCollision(int flag) {
	collision = flag;
	/*
	if (collision != 1) {
		switch (direction) {
		case 0: //up
			upAvailable = true;
			break;
		case 1:
			downAvailable = true;
			break;
		case 2:
			leftAvailable = true;
			break;
		case 3:
			rightAvailable = true;
			break;
		}
	}
	*/
	
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