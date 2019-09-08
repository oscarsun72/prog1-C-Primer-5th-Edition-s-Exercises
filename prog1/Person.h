#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<iostream>
using namespace std;  
struct Person{
//public:
	//Person()=default;
	Person(){
		name = "someone";
		address = "somewhere";
	}
	Person(const string name, const string& address) :name(name),address(address){}
	Person(istream&);
	string addressMethod()const;
	string nameMethod()const;
private:
	string name;
	string address ;

friend	istream& read(istream&, Person&);//read become member function
friend	ostream& print(ostream&, const Person&);

};
istream& read(istream&,Person&);//read become member function
ostream& print(ostream&,const Person&);
#endif