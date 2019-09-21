#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<string>
#include<vector>
//#include<iostream>
using namespace std;
class Account
{
public:
	typedef string str;
	Account(str Name,str telephoneNum,str Address,str Gender);
	//~Account();
	void calculate() {amount+=amount*interestRate;	}
	static double rate() { return interestRate; }
	//static void rate(double);
private:
	str name;//owner
	str no_="000-00-00";// account number
	str tel;//telephone
	str address;
	str gender;
	double amount=0.00;
	vector<str>transactions;
	static double interestRate;
	//static double initRate();//定義上還沒解決
	double initRate();//定義上還沒解決
};

double Account::interestRate = 0.00;

Account::Account(str Name,str telephoneNum,str Address,str Gender)
	:name(Name),tel(telephoneNum),address(Address),gender(Gender)
{
	initRate();	
}

inline double Account::initRate()
{
	return interestRate= 0.0;
}

//
//Account::~Account()
//{
//}

#endif 