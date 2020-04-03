#ifndef FOO_H
#define FOO_H
#include<string>
#include"HasPtr.h"
class Foo
{
	friend void  swap(Foo&,Foo&);
public:
	Foo(const HasPtr& hp) :hp(hp) {}
private:
	HasPtr hp;
};
inline void swap(Foo& lhs, Foo& rhs) {
	//using std::swap;
	swap(lhs.hp, rhs.hp);
}

#endif // !FOO_H