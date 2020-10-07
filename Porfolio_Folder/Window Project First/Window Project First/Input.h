#pragma once

#include <Windows.h>

class Input
{
private:
	struct KeyValue {
		bool BeforePress;
		bool Press;
		KeyValue() :BeforePress(false), Press(false) {}
	};
	KeyValue keys[256];
public:
	void Progress();
	bool GetKey(int key) {
		return keys[key].Press;
	}
	bool GetKeyDown(int key) {
		return keys[key].BeforePress;
	}
};

