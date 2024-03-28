#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
namespace game_framework {
	class character : public ghost{
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;
	protected:
	};
}
