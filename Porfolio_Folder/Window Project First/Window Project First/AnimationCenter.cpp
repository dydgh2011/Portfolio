#include "AnimationCenter.h"

AnimationCenter::~AnimationCenter()
{
	for (auto iter = animations.begin();
		iter != animations.end(); ++iter) {
		delete iter->second;
	}
}
