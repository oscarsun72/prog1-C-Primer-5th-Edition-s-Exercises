﻿// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
//#include "Sales_data.h"

	//const char* a[4] = { "", "V:\\Programming\\C++\\1.txt"
	//	, "V:\\Programming\\C++\\2.txt", "V:\\Programming\\C++\\3.txt" };

#include <iostream>
#include <vector>
using namespace std;

int main() {
	//auto roster1="there is ";
	//vector<const char*>roster2="there is ";
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	const char ca3[] = "A different string";
	vector<const char*>roster1;
	vector<const char*>roster2;
	roster1.push_back(ca1); roster2.push_back(ca1);
	roster1.push_back(ca2); roster2.push_back(ca3);
	//roster1.push_back(ca1);
	//可見比較的是指標（pointer）記憶體位址值，而不是「字串」文字本身
	//可見提供2個迭代器的，其大小一定要等於、小於1個的那個。
	//equal比較的是roster1是否和roster2相等，或為其子集合
	//vector<const char*>roster1{ca1,ca2,ca1};
	//vector<const char*>roster2{ca1,ca2,"1"};
	//vector<const char*>roster1{"there is ","","a"};
	//vector<const char*>roster2{"there is ","","b"};
	auto result = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
	cout <<  result << endl;
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
