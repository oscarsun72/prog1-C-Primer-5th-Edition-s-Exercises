#include "Person.h"

Person::Person(istream& is)
{
	read(cin, *this);
}

string Person::addressMethod() const
{
	return address;
}

string Person::nameMethod() const
{
	return name;
}
istream& Person::read(istream& is,Person& p){//read become member function
	is>>p.name>>p.address;
	return is;
}
ostream& print(ostream& os,const Person& p){
	os<<p.nameMethod()<<'\t'<<p.addressMethod();
	return os;
}