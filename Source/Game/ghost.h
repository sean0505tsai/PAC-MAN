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

	protected:
		int leftX, topY;		// 左上點
		int rightX, bottomY;	// 右下點
		int centerX, centerY;	// 中心點
		int showX, showY;		// 顯示用左上點
		int speed;
		int direction;
		int nextDirection;
		bool collision;
		enum directions{ UP, DOWN, LEFT, RIGHT};
	};

}
