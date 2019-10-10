// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
//#include "Sales_data.h"

	//const char* a[4] = { "", "V:\\Programming\\C++\\1.txt"
	//	, "V:\\Programming\\C++\\2.txt", "V:\\Programming\\C++\\3.txt" };
#include<list>
#include<string>
#include <iostream>
//#include <algorithm>
using namespace std;

int main() {
	list<string>vec{ "0","12","42","3","5050","3900","4050","3050","4650","1200","9950","1800","6465","1230","2400","2600","1900","1900","2600","2835","6450","15266","1800","1800","1800","1080","4320","30","42","43","42","1850","50" };
	string val = "42"; // value we'll look for
// result will denote the element we want if it's in vec, or vec.cend() if not
	auto result = count(vec.cbegin(), vec.cend(), val);
	// report the result
	cout << "The value " << val<< " is found "
		<< (result ==0
			? " is not present" : to_string(result) +" counts") << endl;
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
