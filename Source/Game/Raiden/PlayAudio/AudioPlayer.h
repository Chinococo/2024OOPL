#pragma once
namespace Raiden {
	class AudioPlayer {
	public:
		AudioPlayer(const char*, bool);
		~AudioPlayer();
		void PlayAudio();

	private:
		void StopAudio();
		static unsigned audioIDCounter;
		bool isAudioOpen;
		const char* fileName;
		unsigned audioID;
		bool repeat;
	};
}