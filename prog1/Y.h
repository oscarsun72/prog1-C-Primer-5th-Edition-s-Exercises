#pragma once
#include "X.h"
#ifndef Y_H
#define Y_H

struct  Y {
	int val = 10;
	Y& y;
	Y() = default;
	Y(int v,Y& y) : val(v) ,y(y){}
	X x=X(-10,y);
};
#endif // !Y_H
