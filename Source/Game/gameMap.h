#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
// #include "../Library/gamecore.h"

namespace game_framework {

	class GameMap : public CMovingBitmap
	{
	public:
		void onInit();
		void onShow();
		int isCollision(int x, int y);
	protected:
		int mapMatrix[31][28];
		int lifeCount = 3;
		CMovingBitmap life[3];

	private:
	};
}


