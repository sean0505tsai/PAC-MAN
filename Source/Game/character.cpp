#include "stdafx.h"
#include "character.h"

using namespace game_framework;

void Character::onInit() {

	/*
	leftX = 270;
	topY = 520;
	speed = 4;
	collision = true;
	direction = LEFT;
	currentState = NORMAL;
	nextDirection = LEFT;
	nextDirectionAvailable = false;
	*/
	reset();
	loadUpRES();
	loadDownRES();
	loadLeftRES();
	loadRightRES();
	loadDyingRES();
}

void Character::onMove() {

	if (currentState != DIE) {
		if (currentBlockType == 2) {
			if (leftX <= -19 || leftX >= 540) {
				teleport();
			}
		}

		if (nextDirectionAvailable && nextDirection != direction) {
			direction = nextDirection;
		}
		else if (collision == 0) {

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
}

void Character::setNextDirection(int inputDirection) {
	nextDirection = inputDirection;
}

void Character::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	switch (currentState) {
	case NORMAL:
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
	case DIE:
		dying.SetTopLeft(showX, showY);
		dying.ShowBitmap();
		break;
	}
	
	//SetTopLeft(showX, showY);
	//ShowBitmap();
}

void Character::reset() {
	leftX = 270;
	topY = 520;
	speed = 4;
	collision = true;
	direction = LEFT;
	currentState = NORMAL;
	nextDirection = LEFT;
	nextDirectionAvailable = false;
}

void Character::setCollision(int flag) {
	collision = flag;
}

void Character::setMovingLeft(bool flag) {
	isMovingLeft = flag;
}

void Character::setMovingRight(bool flag) {
	isMovingRight = flag;
}

void Character::setMovingUp(bool flag) {
	isMovingUp = flag;
}

void Character::setMovingDown(bool flag) {
	isMovingDown = flag;
}

bool Character::getNextDirectionAVL() {
	return nextDirectionAvailable;
}

void Character::die(){
	currentState = DIE;
	dying.ToggleAnimation();
}

void Character::loadUpRES() {
	movingUp.LoadBitmapByString({ "Resources/images/bmp/pacman/up/pacman-open-up-1.bmp", 
									"Resources/images/bmp/pacman/up/pacman-open-up-2.bmp", 
									"Resources/images/bmp/pacman/up/pacman-open-up-1.bmp",
									"Resources/images/bmp/pacman/pacman-whole.bmp"}, RGB(255, 255, 255));
	movingUp.SetAnimation(50, false);
}

void Character::loadDownRES() {
	movingDown.LoadBitmapByString({ "Resources/images/bmp/pacman/down/pacman-open-down-1.bmp",
									"Resources/images/bmp/pacman/down/pacman-open-down-2.bmp",
									"Resources/images/bmp/pacman/down/pacman-open-down-1.bmp",
									"Resources/images/bmp/pacman/pacman-whole.bmp" }, RGB(255, 255, 255));
	movingDown.SetAnimation(50, false);
}

void Character::loadLeftRES() {
	movingLeft.LoadBitmapByString({ "Resources/images/bmp/pacman/left/pacman-open-left-1.bmp",
									"Resources/images/bmp/pacman/left/pacman-open-left-2.bmp",
									"Resources/images/bmp/pacman/left/pacman-open-left-1.bmp",
									"Resources/images/bmp/pacman/pacman-whole.bmp" }, RGB(255, 255, 255));
	movingLeft.SetAnimation(50, false);
}

void Character::loadRightRES() {
	movingRight.LoadBitmapByString({ "Resources/images/bmp/pacman/right/pacman-open-right-1.bmp",
									"Resources/images/bmp/pacman/right/pacman-open-right-2.bmp",
									"Resources/images/bmp/pacman/right/pacman-open-right-1.bmp",
									"Resources/images/bmp/pacman/pacman-whole.bmp" }, RGB(255, 255, 255));
	movingRight.SetAnimation(50, false);
}

void Character::loadDyingRES() {
	dying.LoadBitmapByString({"Resources/images/bmp/pacman/die/pacman-die-1.bmp", 
								"Resources/images/bmp/pacman/die/pacman-die-2.bmp", 
								"Resources/images/bmp/pacman/die/pacman-die-3.bmp", 
								"Resources/images/bmp/pacman/die/pacman-die-4.bmp",
								"Resources/images/bmp/pacman/die/pacman-die-5.bmp",
								"Resources/images/bmp/pacman/die/pacman-die-6.bmp",
								"Resources/images/bmp/pacman/die/pacman-die-7.bmp"}, RGB(255, 255, 255));
	dying.SetAnimation(200, true);
}
