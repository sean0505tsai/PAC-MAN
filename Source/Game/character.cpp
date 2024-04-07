#include "stdafx.h"
#include "character.h"

using namespace game_framework;

void Character::onInit() {
	LoadBitmapByString({"Resources/images/bmp/pacman-open-left.bmp"}, RGB(255, 255, 255));
	leftX = 50;
	topY = 80;
	speed = 2;
	collision = false;
	direction = LEFT;
}

void Character::onMove() {
	if (!collision) {
		switch (direction) {
		case LEFT:
			leftX -= speed;
			break;
		case RIGHT:
			leftX += speed;
			break;
		case UP:
			topY -= speed;
			break;
		case DOWN:
			topY += speed;
			break;
		}
	}
}

void Character::changeDirection(int inputDirection) {
	direction = inputDirection;
}

void Character::onShow() {
	showX = leftX - 8;
	showY = topY - 7;
	SetTopLeft(showX, showY);
	ShowBitmap();
}
