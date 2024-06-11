#pragma once
#include <../Library/gameutil.h>
// #include <../Game/ghost.h>
#include <../Game/ghostEntity.h>
namespace game_framework {
	class Clyde : public ghostEntity {
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;

		// setting
		void reset();
		int getDirectionIndex();
		int reverseDirection();
		int reverseIndex();
		bool newDirectionAvailable(int newdirection);
		void setDirectionCollision(int flag, int direction);
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
		//time
		void setCurrentTime(int time);
		void frighten(int seconds);
		void CountDown();

	protected:
		int collision;
		int nextDIRinput;
		// int currentState;
		// int weakenstart = 0;
		// int currentTime;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
		//animation function
		CMovingBitmap countdown;
		CMovingBitmap dying;
		void loadUpRES();
		void loadDownRES();
		void loadLeftRES();
		void loadRightRES();
		void loadWeakRES();
		void loadCountRES();
	};
}
