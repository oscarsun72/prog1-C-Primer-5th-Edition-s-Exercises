// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


//#include"prog1.h"
//#include "Chapter6.h"//標準程式庫才用角括弧
//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
//#include "Sales_item.h"//自訂的標頭檔則用雙引號
//#include<string>

#include <iostream>//標準程式庫才用角括弧
#include<vector>
#include "Sales_data.h"
#include "Person.h"
using namespace std;

ostream& print(ostream& os, Sales_data sales_data) {
	os << sales_data.isbn() << '\t' <<sales_data.soldQ << '\t' 
		<<sales_data.revenue<< '\t' << sales_data.avg_price();
	return os;
}

istream& read(istream& is, Sales_data& sales_data) {//要改變引數值，參數一定要是參考，將引數用傳址（參考）方式傳遞
//decltype(cin)& read(istream is ,Sales_data sales_data) {
	is >> sales_data.bookNo>>sales_data.soldQ>>sales_data.revenue;
	return is;
}

int main() {
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (total.bookNo == trans.bookNo)
			{
				total.combine(trans);
			}
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}
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
