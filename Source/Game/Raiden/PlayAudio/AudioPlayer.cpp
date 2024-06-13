#include "stdafx.h"
#include "AudioPlayer.h"
#include "../../../Library/audio.h"
namespace Raiden {
	AudioPlayer::AudioPlayer() {
		isAudioOpen = false;
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

	void AudioPlayer::PlayAudio(const char* fileName) {
		
		if (isAudioOpen) {
			StopAudio(); // 停止之前的音效
		}

		if (!game_framework::CAudio::Instance()->Load(audioID, const_cast<char*>(fileName))) {
			printf("Failed to load audio file: %s\n", fileName);
			return;
		}

		game_framework::CAudio::Instance()->Play(audioID, true); // 重複播放
	}
}