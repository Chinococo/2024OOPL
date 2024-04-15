#pragma once
#include <string>
#include <map>
#include <vector>
#include <atltypes.h>

namespace Raiden
{
	/**
	 * 先用 Register 註冊一個位置並取得專屬 id。
	 * 之後就需要依靠這個專屬 id 來辨認、修改字串。
	 */
	class TextGraphics
	{
	public:
		std::size_t Register(CPoint &&point, std::string text);
		void UpdateText(std::size_t id, std::string text);
		void Show() const;
		void Clear();

	private:
		std::vector<CPoint> points;
		std::vector<std::string> texts;
	};
}
