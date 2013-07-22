// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_SOUNDPLAYER
#define SSVS_SOUNDPLAYER

#include <SFML/Audio.hpp>
#include <SSVUtils/SSVUtils.h>

namespace ssvs
{
	class SoundPlayer
	{
		private:
			struct ManageableSound : public sf::Sound, public ssvu::MemoryManageable { using sf::Sound::Sound; };

			int volume{100};
			ssvu::MemoryManager<ManageableSound> memoryManager;

			inline void refreshVolume() { for(auto& s : memoryManager) s->setVolume(volume); }

		public:
			enum class Mode{Overlap, Override, Abort};

			inline void play(sf::SoundBuffer& mSoundBuffer, Mode mMode = Mode::Overlap)
			{
				for(const auto& s : memoryManager) if(s->getStatus() == sf::Sound::Status::Stopped) memoryManager.del(*s);
				memoryManager.refresh();

				switch(mMode)
				{
					case Mode::Overlap: break;
					case Mode::Override:
						for(const auto& s : memoryManager) if(s->getBuffer() == &mSoundBuffer) s->stop();
						break;
					case Mode::Abort:
						for(const auto& s : memoryManager) if(s->getBuffer() == &mSoundBuffer) return;
						break;
				}

				auto& sound(memoryManager.create(mSoundBuffer));
				sound.setVolume(volume);
				sound.play();
			}
			inline void stop() { for(auto& s : memoryManager) s->stop(); }

			inline void setVolume(int mVolume)	{ volume = mVolume; refreshVolume(); }
			inline int getVolume()				{ return volume; }
	};
}

#endif
