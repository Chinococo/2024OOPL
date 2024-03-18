#include <StdAfx.h>
#include "StageBrazil.h"
#include "../BossBrazil/BossBrazil.h"

namespace Raiden
{
	void StageBrazil::Init()
	{
		background.Init({ "Resources/Background/StageBrazil.bmp", "Resources/Background/StageComplement.bmp" });
		boss = std::make_unique<BossBrazil>(1000);
		boss->Init();
		fighterPool.AddElement({ 50, 50 });
	}

	void StageBrazil::UpdateDerived(const Player &player)
	{
		// TODO: perform stage logic here.
	}

	void StageBrazil::ShowDerived()
	{
		fighterPool.Show();
	}
}
