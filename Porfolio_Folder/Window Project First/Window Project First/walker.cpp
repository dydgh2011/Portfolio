#include "walker.h"

void walker::Progress()
{
	Translate( (20 * Time.Delta()),0);
	if (x > 610) {
		OC.DeleteObject(this);
	}
}
