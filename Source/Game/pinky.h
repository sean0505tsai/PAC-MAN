#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
namespace game_framework {
	class Pinky : public ghost {
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
		void setNextDirection(int direction);
		void setCollision(int flag);
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		bool getNextDirectionAVL();
		//moving
		void moveOutSquare();
		void decideNextDirection();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void reborn();
		//time
		void setCurrentTime(int time);
		void frighten(int seconds);
		void CountDown();

	protected:
		enum state { SCATTER, CHASE, FRIGHTEN, EATEN, COUNTDOWN };
		int collision;
		int nextDIRinput;
		int currentState;
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
