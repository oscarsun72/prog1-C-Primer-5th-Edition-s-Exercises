#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
using namespace std;//千萬不要忘了這個
struct  Sales_data {
	Sales_data() {
		readSeccess = false ; bookNo = "";
		revenue = 0.00; soldQ = 0; bookSize = 0.00;
	}
	//Sales_data() = default;//預設建構器（constructor）用這式會較Sales_data() {}多二個建構器，蓋=default由編譯器創建2個額外的合成的預設建構器（synthesized default constructors）
	//Sales_data() {}//與Sales_data() = default;應是一樣的，然不能寫在最前面，會遮蔽後面的建構器
	//Sales_data() :bookNo{"000-000-000" } {}
	Sales_data(const string &bNo) :bookNo{bNo } {}
	Sales_data(const string &bNo,  const double bSize, const double rvn) :bookNo{ bNo }, bookSize{ bSize }, revenue{rvn} {}
	Sales_data(const string &, const double bSize, const double, const unsigned);//在類別外定義的建構器
	Sales_data(istream &);//在類別外定義的建構器
	//Sales_data(istream& is){read(is, *this);}
	
	bool readSeccess=false;//readSeccess記錄選取成功否
	string bookNo;
	double revenue{ 0.00 };//總營收-營業額
	unsigned soldQ{ 0 };
	double bookSize{0.00};
	Sales_data& combine(const Sales_data&, const Sales_data&);//成員函式宣告一定要在類別內，定義可在此外
	Sales_data& combine(const Sales_data&);//要改變this及其屬性值就不能再在參數列後加上const；因為加上const後this成了指向常值的常值指標，被指向的東西是不能被改變的了
	string isbn()const;	
	double avg_price()const;
};
ostream& print(ostream& , const Sales_data&);
istream& read(istream& , Sales_data& );
Sales_data add(const Sales_data&, const Sales_data&);
#endif // !SALES_DATA_H