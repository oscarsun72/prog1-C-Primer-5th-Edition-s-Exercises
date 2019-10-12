#include "Sales_data.h"
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

Sales_data::Sales_data(const string& bNo, const double bSize, const double price, const unsigned sdQ) {
	bookNo = bNo; soldQ = sdQ; revenue = price * sdQ; bookSize = bSize;
}
Sales_data::Sales_data(istream& is)
{
	read(is, *this);
}
Sales_data& Sales_data::combine(const Sales_data& sales_data1, const Sales_data& sales_data2)
{
	this->bookNo = sales_data1.bookNo;
	this->bookSize = sales_data1.bookSize;
	this->soldQ = sales_data1.soldQ + sales_data2.soldQ;
	this->revenue = sales_data1.revenue + sales_data2.revenue;
	return *this; // TODO: insert return statement here
}
Sales_data& Sales_data::combine(const Sales_data& sales_data)
{
	if (bookNo == "") bookNo = sales_data.bookNo;//因為這是Sales_data類別的成員函式，所以可以直接調用該類別內的所有成員名稱，不必全名稱
	bookSize = sales_data.bookSize;
	soldQ += sales_data.soldQ;
	revenue += sales_data.revenue;
	return *this;// TODO: insert return statement here
}
string Sales_data::isbn()const
{
	return bookNo;
}

double Sales_data::avg_price()const
{
	if (soldQ > 0)
	{
		return revenue / soldQ;
	}
	return 0.0;
}
ostream& print(ostream& os, const Sales_data& sales_data) {
	os << sales_data.isbn() << '\t' << sales_data.soldQ << '\t'
		<< sales_data.revenue << '\t' << sales_data.avg_price();
	return os;
}

istream& read(istream& is, Sales_data& sales_data) {//要改變引數值，參數一定要是參考，將引數用傳址（參考）方式傳遞
//decltype(cin)& read(istream is ,Sales_data sales_data) {
	is >> sales_data.bookNo >> sales_data.soldQ >> sales_data.revenue;
	return is;
}

Sales_data add(const Sales_data& sales_data1, const Sales_data& sales_data2)
{
	Sales_data sum = sales_data1;
	sum.combine(sales_data2);
	return sum;
}

bool compareIsbnLength(const Sales_data& sd1, const Sales_data& sd2)
{
	return sd1.isbn().size() < sd2.isbn().size();
	//return sd1.bookNo.size() < sd2.bookNo.size();//二式皆可，因為目前Sales_data為struct，預設其成員存取權為公開
}

void sortIsbnAscending(vector<Sales_data>&vecSales_data)
{
	sort(vecSales_data.begin(), vecSales_data.end(), compareIsbnLength);
	stable_sort(vecSales_data.begin(), vecSales_data.end(),
		[](const Sales_data& sd1, const Sales_data& sd2)->bool {
			return sd1.isbn() < sd2.isbn(); });//再用string的小於運算子作比較
	//用<即遞增,小的排前面，用>即遞減，大的排前面
	////第2階用售出數量來排序：這樣寫變成全部改用售出數量來排序了
	//stable_sort(vecSales_data.begin(), vecSales_data.end(),
	//	[](const Sales_data& sd1, const Sales_data& sd2)->bool {
	//		return sd1.soldQ < sd2.soldQ; });
}

void sortIsbnDescending( vector<Sales_data> & vecSales_data)
{
	sort(vecSales_data.begin(), vecSales_data.end(),compareIsbnLength);
	stable_sort(vecSales_data.begin(), vecSales_data.end(),
		[](const Sales_data& sd1, const Sales_data& sd2)->bool {
			return sd1.isbn() > sd2.isbn(); });//用string型別的比較//使用lambda 
	////第2階用售出數量來排序：這樣寫變成全部改用售出數量來排序了
	//stable_sort(vecSales_data.begin(), vecSales_data.end(),
	//	[](const Sales_data& sd1, const Sales_data& sd2)->bool {
	//		return sd1.soldQ>sd2.soldQ; });
}
