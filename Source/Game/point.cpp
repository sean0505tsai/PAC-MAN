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

bool game_framework::Point::isOverlap(int inputX, int inputY){
	
	if (energizer) {
		// If one rectangle is on left side of other
		if ((inputX > GetLeft() + 14) || (GetLeft() > inputX + 19)) return false;
		// If one rectangle is above other
		if ((inputY + 19 < GetTop()) || (GetTop() + 14 < inputY)) return false;
	}
	else {
		// If one rectangle is on left side of other
		if ((inputX > GetLeft() + 4) || (GetLeft() > inputX + 19)) return false;
		// If one rectangle is above other
		if ((inputY + 19 < GetTop()) || (GetTop() + 4 < inputY)) return false;
	}
	// If one rectangle is on left side of other
	// if (l1.X > r2.x || l2.x > r1.x)
	// if((inputX > GetLeft() + 19) || (GetLeft() > inputX + 19)) return false;

	// If one rectangle is above other
	// if (r1.y > l2.y || r2.y > l1.y)
	// if((inputY + 19 < GetTop()) || (GetTop()+19 < inputY)) return false;
	
	return true;
}

bool game_framework::Point::isEnergizer(){
	return energizer;
}

bool game_framework::Point::isEaten(){
	return eaten;
}

