#include "Timer.h"

Timer::Timer()
	:delta(0),scale(1),before(std::chrono::high_resolution_clock::now())
{}
