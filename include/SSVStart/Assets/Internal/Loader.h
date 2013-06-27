// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_ASSETS_INTERNAL_LOADER
#define SSVS_ASSETS_INTERNAL_LOADER

#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "SSVStart/Assets/Internal/Helper.h"

namespace ssvs
{
	namespace Internal
	{
		template<typename T> struct Loader // Most resources can be loaded only from Path, Memory or Stream
		{
			template<typename... TArgs> inline static Uptr<T> load(TArgs&&... mArgs) { return Helper<Mode::Load, T>::load(mArgs...); }
		};
		template<> struct Loader<sf::Texture> // Texture can also be loaded from Image
		{
			using T = sf::Texture;
			inline static Uptr<T> load(const std::string& mPath)				{ return Helper<Mode::Load, T>::load(mPath); }
			inline static Uptr<T> load(const void* mData, std::size_t mSize)	{ return Helper<Mode::Load, T>::load(mData, mSize); }
			inline static Uptr<T> load(sf::InputStream& mStream)				{ return Helper<Mode::Load, T>::load(mStream); }
			inline static Uptr<T> load(const sf::Image& mImage)					{ return Helper<Mode::Image, T>::load(mImage); }
		};
		template<> struct Loader<sf::SoundBuffer> // SoundBuffer can also be loaded from samples
		{
			using T = sf::SoundBuffer;
			inline static Uptr<T> load(const std::string& mPath)				{ return Helper<Mode::Load, T>::load(mPath); }
			inline static Uptr<T> load(const void* mData, std::size_t mSize)	{ return Helper<Mode::Load, T>::load(mData, mSize); }
			inline static Uptr<T> load(sf::InputStream& mStream)				{ return Helper<Mode::Load, T>::load(mStream); }
			inline static Uptr<T> load(const sf::Int16* mSamples, std::size_t mSampleCount, unsigned int mChannelCount, unsigned int mSampleRate) { return Helper<Mode::Samples, T>::load(mSamples, mSampleCount, mChannelCount, mSampleRate); }
		};
		template<> struct Loader<sf::Sound> // Sound is not a real "resource", but it's easy to handle it as such - can be loaded only from SoundBuffer
		{
			using T = sf::Sound;
			inline static Uptr<T> load(const sf::SoundBuffer& mSoundBuffer)	{ return Helper<Mode::SoundBuffer, T>::load(mSoundBuffer); }
		};
		template<> struct Loader<sf::Music> // Music can be opened from Path, Memory or StreamloadFromFile
		{
			using T = sf::Music;
			template<typename... TArgs> inline static Uptr<T> load(TArgs&&... mArgs) { return Helper<Mode::Open, T>::load(mArgs...); }
		};
		template<> struct Loader<sf::Shader> // Shader has unique syntax
		{
			using T = sf::Shader;
			template<typename... TArgs> inline static Uptr<T> load(TArgs&&... mArgs) { return Helper<Mode::Shader, T>::load(mArgs...); }
		};

	}
}

#endif