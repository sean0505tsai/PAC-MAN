#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
// #include "../Library/gamecore.h"

namespace game_framework {

	class gameMap : public CMovingBitmap
	{
	public:
		bool isCollision(int x, int y);
	protected:
	private:
		int mapMatrix[30][27];

	};
}


