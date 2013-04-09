// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_GAMEWINDOW
#define SSVS_GAMEWINDOW

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace ssvs
{
	class GameState;
	class TimerBase;
	class StaticTimer;
	class DynamicTimer;

	class GameWindow
	{
		friend class TimerBase;
		friend class StaticTimer;
		friend class DynamicTimer;

		private:
			GameState* gamePtr{nullptr}; // not owned, just pointed to
			sf::RenderWindow renderWindow;
			std::string title{""};
			sf::Clock clock;

			bool running{true}, focus{true};

			unsigned int width, height, antialiasingLevel{3};
			int pixelMultiplier;
			bool fullscreen;

			TimerBase& timer; // owned

			void runInput();

		public:
			GameWindow(const std::string& mTitle, TimerBase& mTimer, unsigned int mScreenWidth = 320, unsigned int mScreenHeight = 240, int mPixelMultiplier = 1, bool mFullscreen = false);
			GameWindow(const GameWindow&) = delete; // non construction-copyable
			GameWindow& operator=(const GameWindow&) = delete; // non copyable
			~GameWindow();

			void run();
			void stop();
			void recreateWindow();

			void clear(sf::Color mColor);
			void draw(const sf::Drawable& mDrawable);
			void pollEvent(sf::Event& mEvent);

			bool isKeyPressed(sf::Keyboard::Key mKey);
			bool isButtonPressed(sf::Mouse::Button mButton);

			// Setters
			void setGameState(GameState& mGameState);
			void setSize(unsigned int mWidth, unsigned int mHeight);
			void setAntialiasingLevel(unsigned int mAntialiasingLevel);
			void setFullscreen(bool mFullscreen);
			void setVsync(bool mEnabled);
			void setMouseCursorVisible(bool mEnabled);
			void setTitle(const std::string& mTitle);
			void setFPSLimit(float mFPSLimit);

			// Getters
			sf::RenderWindow& getRenderWindow();
			sf::Vector2f getMousePosition();
			float getFPS();
			unsigned int getWidth();
			unsigned int getHeight();
			unsigned int getAntialiasingLevel();
			bool getFullscreen();
			bool hasFocus();
	};
}

#endif
