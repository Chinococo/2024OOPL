#pragma once
#include "../State/State.h"
#include "../../../Library/gameutil.h"

namespace Raiden
{
	class SelectControlState : public State
	{
	public:
		void Init() override;
		void Update(Control &&control) override;
		void Show() override;
		bool Over() override;

	private:
		game_framework::CMovingBitmap background;
	};
}
