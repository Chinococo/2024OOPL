#include "stdafx.h"
#include "TextGraphics.h"
#include <ddraw.h>
#include "../../../Library/gameutil.h"
#include "../../../Library/gamecore.h"

namespace Raiden {
	TextGraphics::TextDatum::TextDatum(const CPoint position, const std::string text)
		: position(position), text(text) {}
	std::size_t TextGraphics::RegisterText(const CPoint position, const std::string text) {
		this->text_data.push_back({ position, text });
		return this->text_data.size() - 1;
	}
	void TextGraphics::ChangePosition(const std::size_t index, const CPoint position) {
		this->text_data.at(index).position = position;
	}
	void TextGraphics::ChangeText(const std::size_t index, const std::string text) {
		this->text_data.at(index).text = text;
	}
	void TextGraphics::ShowTexts() const {
		CDC* const cdc = game_framework::CDDraw::GetBackCDC();
		game_framework::CTextDraw::ChangeFontLog(cdc, this->text_size, "Times New Roman", RGB(255, 255, 255));
		for (const TextDatum& text_datum : text_data) {
			const CPoint& position = text_datum.position;
			game_framework::CTextDraw::Print(cdc, position.x, position.y, text_datum.text);
		}
		game_framework::CDDraw::ReleaseBackCDC();
	}
	void TextGraphics::ClearTextData() {
		this->text_data.clear();
	}
	int TextGraphics::GetTextSize() const {
		return this->text_size;
	}
}
