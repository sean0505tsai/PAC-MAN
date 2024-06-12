#include "stdafx.h"
#include <../Game/ghostEntity.h>

using namespace game_framework;

int ghostEntity::getState() {
	return currentState;
}

void ghostEntity::setCurrentTime(int time) {
	currentTime = time;
}

void ghostEntity::frighten(int second){
	currentState = FRIGHTEN;
	speed = 2;
	//record frightened mode start time(initialize)
	weakenStart = second;
	/*if (weakenStart == 0) {
		weakenStart = second;
	}*/
}

void ghostEntity::CountDown(){
	if (weakenStart != 0) {
		int period = currentTime - weakenStart;
		switch (period) {
		case 7:
			currentState = COUNTDOWN;
			break;
		case 10:
			currentState = SCATTER;
			weakenStart = 0;
			speed = 4;
			break;
		}
	}
}
