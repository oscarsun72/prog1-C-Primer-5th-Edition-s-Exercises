#include "Sales_data.h"
#include<string>
using namespace std;
Sales_data& Sales_data::combine(const Sales_data& sales_data1,  const Sales_data& sales_data2)
{
	this->bookNo = sales_data1.bookNo;
	this->bookSize = sales_data1.bookSize;
	this->soldQ = sales_data1.soldQ + sales_data2.soldQ;
	this->revenue = sales_data1.revenue + sales_data2.revenue;
	return *this; // TODO: insert return statement here
}
string Sales_data::isbn(const Sales_data& sales_data)
{
	return sales_data.bookNo;
}

double Sales_data::avg_price(const Sales_data& sales_data)
{
	if (sales_data.soldQ>0)
	{
		return sales_data.revenue / sales_data.soldQ;
	}
	return 0.0;
}
