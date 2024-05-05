#pragma once
#include <atltypes.h>
#include <vector>

namespace Raiden {
	class TextGraphics {
	public:
		std::size_t RegisterText(const CPoint, const std::string = "");
		void ChangePosition(const std::size_t, const CPoint);
		void ChangeText(const std::size_t, const std::string);
		void ShowTexts() const;
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
