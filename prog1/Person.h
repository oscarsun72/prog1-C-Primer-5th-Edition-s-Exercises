#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<iostream>
using namespace std;  
struct Person{
	string addressMethod()const;
	string nameMethod()const;
	private:
	string address ;
	string name;
};
istream& read(istream&,Person&);
ostream& print(ostream&,const Person&);
#endif