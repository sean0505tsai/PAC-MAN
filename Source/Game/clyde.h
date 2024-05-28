#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
namespace game_framework {
	class Clyde : public ghost {
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;

		// setter
		void decideNextDirection();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void setNextDirection(int direction);
		void setCollision(int flag);
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		bool getNextDirectionAVL();
		void normalMove();
		

	protected:
		enum state { Scatter, Chase, Frighten };
		int collision;
		int nextDIRinput;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
	};
}
