#include "stdafx.h"
#include <string>
#include "Source\Game\Raiden\Bomb\Bomb.h"
#include "Source/Game/config.h"
namespace Raiden {
	void Bomb::Init()
	{
		std::vector<std::string> bitmapPaths;
		for (int i = 1; i <= 24; i+=3) {
			bitmapPaths.push_back("Resources\\Bomb\\" + std::to_string(i) + ".bmp");
		}
		sprite.LoadBitmapByString(bitmapPaths, RGB(0, 0, 0));
		this->InitCollisionBox(sprite.GetWidth(), sprite.GetHeight());
	}

	bool Bomb::Start()
	{
		if (!complte) {
			return false;
		}
		this->sprite.SetTopLeft(0, SIZE_Y);
		complte = false;
		return true;
	}
	void Bomb::update()
	{
		if (complte) {
			return;
		}
		if (this->sprite.GetTop() < 0) {
			complte = true;
		}
		else {
			if (!sprite.IsAnimation()) {
				sprite.SetTopLeft(sprite.GetLeft(), sprite.GetTop()-50);
				sprite.SetAnimation(0, true);
				sprite.ToggleAnimation();
				this->UpdateCollisionBox(sprite.GetLeft(), sprite.GetTop());
			}
			
		}
	}
	void Bomb::Show(bool debug)
	{
		if (!complte) {
			this->sprite.ShowBitmap();
			
			if (debug) {
				this->ShowCollisionBox();
			}
		}
	}
	bool Bomb::IsComplte()
	{
		return complte;
	}
}

