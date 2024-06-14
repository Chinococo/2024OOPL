#include "stdafx.h"
#include "AudioPlayer.h"
#include "../../../Library/audio.h"
namespace Raiden {

	unsigned AudioPlayer::audioIDCounter = 0;

	AudioPlayer::AudioPlayer(const char* fileName, bool repeat) {
		isAudioOpen = false;
		this->fileName = fileName;
		this->audioID = audioIDCounter++;
		this->repeat = repeat;

		if (!game_framework::CAudio::Instance()->Load(audioID, const_cast<char*>(fileName))) {
			printf("Failed to load audio file: %s\n", fileName);
			return;
		}
	}

	AudioPlayer::~AudioPlayer() {
		if (isAudioOpen) {
			game_framework::CAudio::Instance()->Close();
		}
	}

	void AudioPlayer::StopAudio() {
		if (isAudioOpen) {
			game_framework::CAudio::Instance()->Stop(audioID);
		}
	}

	void AudioPlayer::PlayAudio() {
		
		if (isAudioOpen) {
			StopAudio(); // 停止之前的音效
		}

		game_framework::CAudio::Instance()->Play(audioID, repeat); // 重複播放
	}
}