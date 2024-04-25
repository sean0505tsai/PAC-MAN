#include "stdafx.h"
#include "point.h"
using namespace game_framework;

void Point::onInit() {
	LoadBitmapByString({"Resources/images/bmp/small-point.bmp", 
							"Resources/images/bmp/big-point.bmp", 
							"Resources/images/bmp/point-empty.bmp"}, RGB(0, 0, 0));
	energizer = false;
	eaten = false;
}

void game_framework::Point::setEnergizer(bool flag){
	energizer = flag;
	SetFrameIndexOfBitmap(1);
}

void game_framework::Point::setEaten(bool flag){
	eaten = flag;
	SetFrameIndexOfBitmap(2);
}

bool game_framework::Point::isLevelPass(){
	return false;
}

bool game_framework::Point::isEnergizer(){
	return false;
}

bool game_framework::Point::isEaten(){
	return eaten;
}

