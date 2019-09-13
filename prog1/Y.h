#ifndef Y_H
#define Y_H
#include "X.h"
struct  Y {
	int val = 10;
	Y() = default;
	Y(int v) : val(v) {}
	X x;
};
#endif // !Y_H
