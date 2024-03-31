#include "stdafx.h"
#include "State.h"

namespace Raiden
{
	void State::Init()
	{
		xml_reader.Init();
		InitDerived();
	}
}
