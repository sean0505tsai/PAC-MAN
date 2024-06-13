#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghostEntity.h>
//#include <../Game/gameMap.h>  
namespace game_framework {
	class Blinky : public ghostEntity {
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;

		// setting
		void reset();
		int getDirectionIndex();
		bool newDirectionAvailable(int newdirection);
		void setDirectionCollision(int flag, int direction);
		int reverseDirection();
		int reverseIndex();
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

	protected:
		int newDirection;
		vector<pair<int, int>> road;
		int collision;
		int horDirection;
		int verDirection;
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
		//­«¥Í
		void loadUpDEAD();
		void loadDownDEAD();
		void loadLeftDEAD();
		void loadRightDEAD();
		/*
		*/
	};
}
