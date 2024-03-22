#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
// #include "../Library/gamecore.h"

namespace game_framework {
	
	class ghost : public CMovingBitmap {
	public:
		virtual void onMove();

	protected:
		int speed;					// ���ʳt��
		int currentDirection;		// �ثe���ۤ�V
		int currentState;			// �ثe���A
		enum direction{UP, DOWN, LEFT, RIGHT};
		enum state{STRONG, WEAK};		// ���A: �L��/��z
	};

	class Character : public ghost {
	public:
		virtual void onMove() override;
		bool isAlive();				// �O�_���`
	private:
		int lifeCount;				// �ͩR��
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

