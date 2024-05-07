#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
namespace game_framework {
	class Blinky : public ghost {
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;

		// setter
		void setNextDirection(int direction);
		void setCollision(int flag);
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		bool getNextDirectionAVL();
		void findPath(int targetX, int targetY);
		void scatterMove();
		void findPacman();

	protected:
		enum state { Scatter, Chase, Frighten, dead };
		int collision;
		int nextDIRinput;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
	};
}
