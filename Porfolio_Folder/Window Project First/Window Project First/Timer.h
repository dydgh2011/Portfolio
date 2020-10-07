#pragma once

#include <chrono>
#include <Windows.h>

class Timer
{
private:
	double delta;
	double scale;
	std::chrono::steady_clock::time_point before;
public:
	void SetScale(double scale) { this->scale = scale; }
	double GetScale() const { return scale; }
	double Delta() const {
		return scale * delta;
	}
	void CheckTimer() {
		auto after = std::chrono::high_resolution_clock::now();
		delta = (after - before).count() / 1000000000.0;
		before = after;
	}
public:
	Timer();
};

