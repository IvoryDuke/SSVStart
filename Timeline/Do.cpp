// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "Do.h"
#include "Timeline.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace ssvs
{
	Do::Do(Action mAction) : action{mAction} { }
	void Do::update(float) { action(); timelinePtr->next(); }
} /* namespace sses */
