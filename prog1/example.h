#ifndef EXAMPLE_H
#define EXAMPLE_H
#include<vector>
using namespace std;//別忘了vector是 std::vector!!!
// example.h
class Example {
public:
	static double rate;
	static const int vecSize = 20;
	static vector <double> vec;
};
#endif