#include "Y.h"
#ifndef X_H
#define X_H
class X {
	int val = -10;
public:
	Y y(55);
	Y * yPtr=&y;
	inline int rtnval() { return val; }
};
#endif // !X_H
