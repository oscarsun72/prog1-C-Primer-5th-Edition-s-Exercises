// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


//#include"prog1.h"
//#include "Chapter6.h"//標準程式庫才用角括弧
//using std::cout; using std::cin;using std::endl;
//#include<cassert>

#include <iostream>//標準程式庫才用角括弧
#include<vector>
#include<string>
#include "Sales_item.h"//自訂的標頭檔則用雙引號
#include "Sales_data.h"
using namespace std;



int main() {
	Sales_data book;
	vector<Sales_data> vecSd;
	int i = 1;
	if (cin>>book.bookNo)
	{
		while (cin)//這可以處理到讀完輸入止，不限交易記錄筆數
		{
			i++;
			switch (i % 3)
			{
			case 1:
				cin >> book.bookNo;
				break;
			case 2:
				cin>> book.soldQ;
				break;
			case 0:
				cin>>book.revenue;
				vecSd.push_back(book);
				break;
			default:
				break;			
			}
		}
	}
	else
	{
		cerr << "沒有資料？！" << endl;
		return -1;
	}
	i = 0; unsigned ctr = 1;
	Sales_data dataPrevious;
	for (Sales_data Sd : vecSd)
	{
		if (i > 0)
			if (Sd.bookNo == dataPrevious.bookNo)
			{
				++ctr;
			}
			else
			{
				if (!ctr)
				{					
					cout << dataPrevious.bookNo << '\t' << "有 " << ctr << " 筆" << endl;					
				}
				else
				{
					cout << dataPrevious.bookNo << '\t' << "有 " << ctr  << " 筆" << endl;
					ctr = 1;
				}
			}
		++i;
		dataPrevious = Sd;
	}
	cout << dataPrevious.bookNo << '\t' << "有 " << ctr << " 筆" << endl;
	return 0;
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
