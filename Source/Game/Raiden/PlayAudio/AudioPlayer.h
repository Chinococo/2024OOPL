#pragma once
namespace Raiden {
	class AudioPlayer {
	public:
		AudioPlayer();
		~AudioPlayer();
		void PlayAudio(const char* fileName);

	private:
		bool isAudioOpen;
		unsigned audioID;
		void StopAudio();
	};
}