// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_GAMESYSTEM_TIMERS_STATIC
#define SSVS_GAMESYSTEM_TIMERS_STATIC

#include "SSVStart/GameSystem/Timers/TimerBase.h"

namespace ssvs
{
	class GameWindow;

	class StaticTimer : public TimerBase
	{
		private:
			float step, timeSlice, maxLoops, time{0}, loops{0};

		public:
			StaticTimer(GameWindow& mGameWindow, float mStep = 1.f, float mTimeSlice = 1.f, float mMaxLoops = 50);
			~StaticTimer() { }

			void runUpdate() override;

			// Setters
			inline void setStep(float mStep)			{ step = mStep; }
			inline void setTimeSlice(float mTimeSlice)	{ timeSlice = mTimeSlice; }
			inline void setMaxLoops(float mMaxLoops)	{ maxLoops = mMaxLoops; }

			// Getters
			inline float getStep() const		{ return step; }
			inline float getTimeSlice() const	{ return timeSlice; }
			inline float getMaxLoops() const	{ return maxLoops; }
			inline float getTime() const		{ return time; }
			inline float getLoops() const		{ return loops; }
	};

	StaticTimer& createStaticTimer(GameWindow& mGameWindow, float mStep = 1.f, float mSpeed = 1.f, float mMaxLoops = 50);
}

#endif
