/* The MIT License (MIT)
 * Copyright (c) 2012 Vittorio Romeo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef TIMELINE_H_
#define TIMELINE_H_

#include <vector>

using namespace std;

namespace ssvs
{
	class Command;

	class Timeline
	{
		friend class Wait;
		friend class Do;
		friend class Goto;

		private:
			vector<Command*> commandPtrs; // owned
			Command* currentCommandPtr { nullptr };

			float timeNext { 0 };
			bool ready { true };
			bool finished { false };

			void next();
			void step();

		public:
			~Timeline();

			bool isFinished();
			void insert(int, Command*);
			void push_back(Command*);
			void del(Command*);
			void update(float);
			void jumpTo(int);
			void reset();
			void clear();
			int getSize();
			int getCurrentIndex();
	};
} /* namespace sses */
#endif /* TIMELINE_H_ */
