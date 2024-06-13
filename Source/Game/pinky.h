#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghostEntity.h>
namespace game_framework {
	class Pinky : public ghostEntity {
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;

		// setting
		void reset();
		void reset(int second);
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

	protected:
		int collision;
		int nextDIRinput;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
		CMovingBitmap countdown;
		CMovingBitmap dying;

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
