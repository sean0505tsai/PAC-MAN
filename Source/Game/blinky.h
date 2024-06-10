#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
//#include <../Game/gameMap.h>  
namespace game_framework {
	class Blinky : public ghost {
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;

		// setting
		void reset();
		void getEaten();
		int getDirectionIndex();
		bool newDirectionAvailable(int newdirection);
		void setDirectionCollision(int flag, int direction);
		int reverseDirection();
		int reverseIndex();
		int getCurrentState();
		void setCollision(int flag);
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		bool getNextDirectionAVL();
		// moving
		void moveOutSquare();
		void decideNextDirection();
		void setNextDirection(int direction);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void reborn();
		// time
		void setCurrentTime(int time);
		void frighten(int seconds);
		void CountDown();

	protected:
		int newDirection;
		vector<pair<int, int>> road;
		//int currentBlockType;
		enum state { SCATTER, CHASE, FRIGHTEN, EATEN , COUNTDOWN};
		int currentState;
		int collision;
		int horDirection;
		int verDirection;
		int nextDIRinput;
		int weakenstart = 0;
		int currentTime;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
		CMovingBitmap countdown;
		CMovingBitmap dying;
		bool eaten = false;
		int eatencount = 0;

		void loadUpRES();
		void loadDownRES();
		void loadLeftRES();
		void loadRightRES();
		void loadWeakRES();
		void loadCountRES();

		/*
		*/
	};
}
