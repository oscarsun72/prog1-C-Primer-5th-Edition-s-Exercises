#pragma once
#include "Y.h"
#ifndef X_H
#define X_H

class X {
	int val = -10;
	Y y=Y(55,*yPtr);
public:
	X() = default;
	X(int v,Y &y) :val(v),y(y),yPtr(&y) {}
	Y * yPtr=&y;
	inline int rtnval() { return val; }
};
#endif // !X_H
