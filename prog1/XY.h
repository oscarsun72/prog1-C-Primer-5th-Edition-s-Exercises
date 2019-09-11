#ifndef XY_H
#define XY_H
class X {
	int val = 0;
public:
	Y* yPtr;

};
struct  Y {
	int val = 0;
	Y(int v): val(v) {}
	X x;
};
#endif // !XY_H
