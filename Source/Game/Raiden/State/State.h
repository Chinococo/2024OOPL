#pragma once
#include "../Control/Control.h"
#include "../Xml/XmlReader.h"

namespace Raiden
{
	class State
	{
	public:
		virtual ~State() = default;
		void Init();
		virtual void InitDerived() = 0;
		virtual void KeyUp(Control &control) = 0;
		virtual void Update(Control &control) = 0;
		virtual void Show() = 0;
		virtual bool Over() = 0;

	protected:
		XmlReader xml_reader;
	};
}
