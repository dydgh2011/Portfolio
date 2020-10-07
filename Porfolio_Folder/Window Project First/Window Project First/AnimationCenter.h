#pragma once

#include<Windows.h>
#include<map>
#include<string>

class Animation {
public:
	int scNumber;
	int Begin;
	int End;
	Animation(int scN, int B, int E) :scNumber(scN), Begin(B), End(E) {}
};

class AnimationCenter
{
private:
	std::map<std::string, Animation*> animations;
public:
	Animation* operator[](std::string key) {
		return animations[key];
	}
public:
	void Push(std::string key, int scNumber, int Begin, int End) {
		animations.insert(std::make_pair(key, new Animation(scNumber, Begin, End)));
	}
	int Check(std::string key, int index) {
		if (animations[key]->Begin > index)
			return animations[key]->Begin;
		if (animations[key]->End < index)
			return animations[key]->Begin;
		return index;
	}
	~AnimationCenter();
};

