// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//#include"prog1.h"
//#include "Chapter6.h"//標準程式庫才用角括弧
//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
//#include "Sales_item.h"//自訂的標頭檔則用雙引號
//#include<vector>
//#include "Sales_data.h"
//#include "Person.h"
//#include "Screen.h"
#include<string>
#include <iostream>
using namespace std;
class Sales_data {
	string bookNo;
	unsigned units_sold=0;
	double revenue=0.0;	
public:
	// defines the default constructor as well as one that takes a string argument
	Sales_data(std::string s ) : bookNo(s) { }
	// remaining constructors unchanged
	Sales_data(std::string s, unsigned cnt, double rev) :
		bookNo(s), units_sold(cnt), revenue(rev* cnt) { }
	Sales_data(std::istream& is = cin) { read(is, *this); }
	// remaining members as before
	friend istream& read(istream&, Sales_data&);
	friend ostream& print(ostream& os, const Sales_data& sales_data);
};

istream& read(istream&, Sales_data&);

istream& read(istream& is, Sales_data& sales_data) {//要改變引數值，參數一定要是參考，將引數用傳址（參考）方式傳遞
//decltype(cin)& read(istream is ,Sales_data sales_data) {
	is >> sales_data.bookNo >> sales_data.units_sold >> sales_data.revenue;
	return is;
}

ostream& print(ostream& os, const Sales_data& sales_data) {
	os << sales_data.bookNo << '\t' << sales_data.units_sold << '\t'
		<< sales_data.revenue  ;
	return os;
}

Sales_data first_item(cin);//Sales_data(std::istream& is = cin) { read(is, *this); }

int main() {
	Sales_data next;//Sales_data(std::istream& is = cin) { read(is, *this); }
	Sales_data last("9-999-99999-9");//Sales_data(std::string s ) : bookNo(s) { }

	print(cout,first_item); cout << endl;
	print(cout,next); cout << endl;
	print(cout, last); cout << endl;
}



//int main(int argc, const char** argv)
//{
//	print_sum_of_the_elements_in_the_list({ 11,2,3 });
//	return 0;
//}


			//printf("%i\n", i);
			//std::cout << "Hello World!\n";



// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
