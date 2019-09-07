// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


//#include"prog1.h"
//#include "Chapter6.h"//標準程式庫才用角括弧
//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
//#include "Sales_item.h"//自訂的標頭檔則用雙引號
//#include<string>
//include "Person.h"
#include<vector>
#include "Sales_data.h"
#include <iostream>
using namespace std;
int main() {	
	Sales_data sd ;//和下式一樣，只是在Visual Studio預選清單中，它是從第2個建構器來讓我們選的
	Sales_data sd1 = Sales_data();//可見Sales_data sd的Sales_data() 就是預設的第一個建構器
	Sales_data& rSd=sd; Sales_data& rrSd=rSd;
	Sales_data sd2= Sales_data(rSd);//這2個建構器是編譯器自己訂的
	Sales_data sd21= Sales_data(rrSd);//這2個建構器是編譯器自己訂的
	Sales_data sd3= Sales_data(cin);//這個在建構時須輸入才能執行
	Sales_data sd4= Sales_data("978-986-502-172-6(平裝）");
	Sales_data sd5= Sales_data("978-986-502-172-6(平裝）",24.01,310.11);
	Sales_data sd6= Sales_data("978-986-502-172-6(平裝）",24.01, 110.1,3);

	const vector<Sales_data> vecSd{sd,rSd,rrSd,sd1,sd2,sd21,sd3,sd4,sd5,sd6};
	for (Sales_data i:vecSd)
	{
			print(cout,i)<<"\n"<<endl;		
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
