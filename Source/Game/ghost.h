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
		int getX();			// 取得左上點X座標
		int getY();			// 取得左上點Y座標
		int getRightX();
		int getBottomY();
		int getSpeed();
		int getDirection();
		int getNextDirection();
		void setNextDirAVL(bool flag);

	protected:
		int leftX, topY;		// 左上點
		int rightX, bottomY;	// 右下點
		int showX, showY;		// 顯示用左上點
		int speed;
		int direction;
		int directionIndex;
		int nextDirection;
		int collisionType;
		bool nextDirectionAvailable;
		enum directions{ UP, DOWN, LEFT, RIGHT};
	};

}
