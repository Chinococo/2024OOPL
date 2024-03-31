#pragma once
#include "../State/State.h"
#include "../../../Library/gameutil.h"
#include <vector>
#include <atltypes.h>

namespace Raiden
{
	class SelectControlState : public State
	{
	public:
		void InitDerived() override;
		void KeyUp(Control &control) override;
		void Update(Control &control) override;
		void Show() override;
		bool Over() override;

	private:
		bool mode_selected = false;
		game_framework::CMovingBitmap background;
		game_framework::CMovingBitmap selection_line;
		std::vector<CPoint> selection_line_position;
		std::size_t selection_index = 0;
	};
}
