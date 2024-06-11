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
	//record frightened mode start time(initialize)
	if (weakenstart == 0) {
		weakenstart = second;
	}
}

void ghostEntity::CountDown(){
	if (weakenstart != 0) {
		int period = currentTime - weakenstart;
		switch (period) {
		case 7:
			currentState = COUNTDOWN;
			break;
		case 10:
			currentState = SCATTER;
			weakenstart = 0;
			break;
		}
	}
}
