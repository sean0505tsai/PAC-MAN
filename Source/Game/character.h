#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
namespace game_framework {
	class Character : public ghost{
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;
		void changeDirection(int direction);
		void setCollision(int type);
	protected:
		enum state{ STRONG, WEAK };
		int collisionType;
	};
}
