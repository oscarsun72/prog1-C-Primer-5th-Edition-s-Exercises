#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
struct  Sales_data {
	std::string bookNo;
	double revenue{ 0.00 };
	unsigned soldQ{ 0 };
	double bookSize;
};
#endif // !SALES_DATA_H


