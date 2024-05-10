#include "stdafx.h"
#include "blinky.h"

using namespace game_framework;

void Blinky::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost-blinky-right.bmp" }, RGB(255, 255, 255));
	leftX = 270;
	//leftX = 120;
	topY = 280;
	speed = 4;
	collision = true;
	direction = RIGHT;
	state currentState = SCATTER;

	nextDirection = UP;
	nextDirectionAvailable = false;
}

void Blinky::onMove() {
		//current state = scatter
	if (1 == 1) {
		scatterMove();
	}
	//else if () {}


	// ����V
	if (nextDirectionAvailable && nextDirection != direction) {
		direction = nextDirection;
	}
	else
		/*Direction to be automated by using function*/
		if (collision == 0) {

			switch (direction) {
			case UP:
				topY -= speed;
				break;
			case DOWN:
				topY += speed;
				break;
			case LEFT:
				leftX -= speed;
				break;
			case RIGHT:
				leftX += speed;
				break;
			}

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
}

void Blinky::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	SetTopLeft(showX, showY);
	ShowBitmap();
}

void Blinky::findPath(int targetX, int targetY) { //let ghost find the properly path for moving to the target

	/*
	Direction priority up(0) > left(2) > down(1) > right(3)
	*/
	verDirection = (targetY - topY) < 0 ? 0 : 1;
	horDirection = (targetX - leftX) > 0 ? 3 : 2;
}

void Blinky::scatterMove() {
	//I.�����w�i�J¶��y�D��
	if (leftX >= 420 && leftX <= 520 && topY <= 160 && topY >= 80) {
		//¶��ήخذf�ɰw�](420, 80)->(520, 160)

	}
	//II.�������b�y�D�d�� 
	else {
		//�i�J�y�D�_�l�I
		findPath(420, 80);
	}
}

void Blinky::findPacman() {

}

void Blinky::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
}

void Blinky::setCollision(int flag) {
	collision = flag;
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