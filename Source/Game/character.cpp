#include "stdafx.h"
#include "character.h"

using namespace game_framework;

void character::onInit() {
	LoadBitmapByString({"Resources/images/bmp/pacman-open-left.bmp"}, RGB(255, 255, 255));
	x = 0;
	y = 0;
}

void character::onMove() {

}

void character::onShow() {
	SetTopLeft(x, y);
}
