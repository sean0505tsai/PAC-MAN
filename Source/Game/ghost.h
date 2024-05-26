#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
// #include "../Library/gamecore.h"

namespace game_framework {
	
	class ghost : public CMovingBitmap {
	public:
		virtual void onInit();
		virtual void onMove();
		virtual void onShow();
		int getX();			// ���o���W�IX�y��
		int getY();			// ���o���W�IY�y��
		int getRightX();
		int getBottomY();
		int getSpeed();
		int getDirection();
		int getNextDirection();
		void setNextDirAVL(bool flag);

	protected:
		int leftX, topY;		// ���W�I
		int rightX, bottomY;	// �k�U�I
		int showX, showY;		// ��ܥΥ��W�I
		int speed;
		int direction;
		int directionIndex;
		int nextDirection;
		int collisionType;
		bool nextDirectionAvailable;
		enum directions{ UP, DOWN, LEFT, RIGHT};
	};

}
