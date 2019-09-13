#pragma once
#include "Y.h"
#ifndef X_H
#define X_H
class X {
	int val = -10;
	Y y=Y(55);
public:
	X() = default;
	X(int v) :val(v) {}
	Y * yPtr=&y;
	inline int rtnval() { return val; }
};
#endif // !X_H
