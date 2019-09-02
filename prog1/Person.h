#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std;  
struct Person{
	string address ;
	string name;
	string addressMethod()const;
	string nameMethod()const;
};
#endif