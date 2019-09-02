#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
using namespace std;//千萬不要忘了這個
struct  Sales_data {
	string bookNo;
	double revenue{ 0.00 };//總營收-營業額
	unsigned soldQ{ 0 };
	double bookSize{0.00};
	Sales_data& combine(const Sales_data&, const Sales_data&);//成員函式宣告一定要在類別內，定義可在此外
	Sales_data& combine(const Sales_data&);//要改變this及其屬性值就不能再在參數列後加上const；因為加上const後this成了指向常值的常值指標，被指向的東西是不能被改變的了
	string isbn()const;	
	double avg_price()const;
};
#endif // !SALES_DATA_H


