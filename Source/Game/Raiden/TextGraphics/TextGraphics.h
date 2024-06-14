#pragma once
#include <atltypes.h>
#include <vector>

namespace Raiden {
	class TextGraphics {
	public:
		std::size_t RegisterText(std::size_t, CPoint, const std::string = "");
		void ShowTexts() const;
		void ClearTextData();
		int GetTextSize() const;
	private:
		struct TextDatum {
			TextDatum(const CPoint, const std::string);
			CPoint position;
			std::string text;
		};
		std::vector<TextDatum> text_data;
		const int text_size = 30;
	};
}
