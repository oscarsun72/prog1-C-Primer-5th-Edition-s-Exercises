#pragma once
#include "X.h"
#ifndef Y_H
#define Y_H

struct  Y {
	int val = 10;
	Y() = default;
	Y(int v) : val(v) {}
	X x=X(-10);
};
#endif // !Y_H
