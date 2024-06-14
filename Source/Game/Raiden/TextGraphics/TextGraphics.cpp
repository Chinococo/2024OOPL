#include "stdafx.h"
#include "TextGraphics.h"
#include <ddraw.h>
#include "../../../Library/gameutil.h"
#include "../../../Library/gamecore.h"

namespace Raiden {
	TextGraphics::TextDatum::TextDatum(const CPoint position, const std::string text)
		: position(position), text(text) {}
	std::size_t TextGraphics::RegisterText(std::size_t index, CPoint position, const std::string text) {
		if (index < 0 || index >= this->text_data.size()) {
			this->text_data.push_back({ position, text });
			return this->text_data.size() - 1;
		}
		else {
			this->text_data.at(index) = { position, text };
			return index;
		}
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
