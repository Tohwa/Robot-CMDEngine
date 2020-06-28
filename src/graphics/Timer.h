#pragma once

#include <chrono>

#include <functional>

namespace Robot {


	class Timer
	{
	public:
		typedef std::function<void()> TimerFunc;

		void ExecuteInterval(TimerFunc func, int interval);

		static void SetTimeout(int timeout);

		void Stop()
		{
			hasInterval = false;
		}

	private:
		bool hasInterval = false;
	};

}
