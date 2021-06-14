#include "Timer.h"

#include <thread>

namespace Robot {

	/* Warning: If you are using clang or gcc, you have to enable the option -lpthread,
	   in order to compile this application successfully, if you are using MSVC it should be fine.*/

	/* Achtung: Damit das Program erfolgreich läuft muss, sofern clang oder gcc als Compiler benutzt wird,
	   die Option -lpthread in den Compilier Befehl inkludiert werden. Unter MSVC sollte alles funktionieren.*/

	void Timer::ExecuteInterval(TimerFunc func, int interval)
	{
		hasInterval = true;

		std::thread t([=]() {

			while (true) {

				if (!hasInterval) return;
				std::this_thread::sleep_for(std::chrono::milliseconds(interval));
				if (!hasInterval) return;
				func();
			}

			});

		t.detach();
	}

	void Timer::SetTimeout(int timeout)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
	}

}
