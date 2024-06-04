#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
namespace game_framework {
	class Character : public ghost{
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;
		void reset() override;
		
		// setter
		void setNextDirection(int direction);
		void setCollision(int flag);
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		void setEnergize();

		// getter
		bool getNextDirectionAVL();
		bool isEnergizing();
		// int getState();

		// operation
		void die();
		bool isOverLap(int x, int y);
	
	protected:
		enum state{ NORMAL, DIE };
		int collision;
		int nextDIRinput;
		int currentState;
		int energizeStart;
		bool energize;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
		CMovingBitmap dying;
		
		void loadUpRES();
		void loadDownRES();
		void loadLeftRES();
		void loadRightRES();
		void loadDyingRES();
		void resetEnergize();

	};
}
