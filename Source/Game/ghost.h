#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
// #include "../Library/gamecore.h"

namespace game_framework {
	
	class ghost : public CMovingBitmap {
	public:
		virtual void onMove();

	protected:
		int speed;					// 移動速度
		int currentDirection;		// 目前面相方向
		int currentState;			// 目前狀態
		enum direction{UP, DOWN, LEFT, RIGHT};
		enum state{STRONG, WEAK};		// 狀態: 無敵/虛弱
	};

	class Character : public ghost {
	public:
		virtual void onMove() override;
		bool isAlive();				// 是否死亡
	private:
		int lifeCount;				// 生命數
	};

	class RedGhost : public ghost {
	public:
		virtual void onMove() override;
	};

	class OrangeGhost : public ghost {
	public:
		virtual void onMove() override;
	};

	class BlueGhost : public ghost {
	public:
		virtual void onMove() override;
	};

	class PinkGhost : public ghost {
	public:
		virtual void onMove() override;
	};
}

