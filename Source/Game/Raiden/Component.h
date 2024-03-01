#pragma once

namespace Raiden
{
	class Component
	{
	public:
		virtual ~Component() = default;
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Show() = 0;
	};
}
