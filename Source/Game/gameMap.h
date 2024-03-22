#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
// #include "../Library/gamecore.h"

namespace game_framework {

	class GameMap : public CMovingBitmap
	{
	public:
		bool isCollision(int x, int y);
	protected:
	private:
		bool isLevelPass;
		int mapMatrix[30][27];
		CMovingBitmap point;
		CMovingBitmap lifeCount[3];				// 顯示生命數
	};
}
