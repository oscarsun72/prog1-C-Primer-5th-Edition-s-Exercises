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
	Sales_data& combine(const Sales_data&);//成員函式宣告一定要在類別內，定義可在此外
	string isbn()const;	
	double avg_price(const Sales_data&)const;
};
#endif // !SALES_DATA_H


