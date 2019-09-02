#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<iostream>
using namespace std;  
struct Person{
	string address ;
	string name;
	string addressMethod()const;
	string nameMethod()const;
};
istream& read(istream&,Person&);
ostream& print(ostream&,const Person&);
#endif