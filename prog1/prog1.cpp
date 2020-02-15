// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<unordered_map>
#include"Sales_data.h"

using namespace std;
size_t hasher(const Sales_data& sd) {
	return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data& lhs, const Sales_data rhs) {
	/*	return lhs.isbn() == rhs.isbn()&&lhs.bookSize==rhs.bookSize
	&& lhs.revenue == rhs.revenue;*/
	return lhs.isbn() == rhs.isbn();
}

int main() {
	Sales_data sd;
	typedef unordered_map<Sales_data, size_t, decltype(hasher)*
		, bool(*)(const Sales_data & lhs, const Sales_data rhs)> um;
	/*arguments are the bucket size and pointers to the hash function
		and equality operator*/
	um m(42, hasher, eqOp);//頁466。也就是這種自定義類別為鍵值的無序容器是沒有預設建構器，一定都要傳入這樣的引數才行
	while (read(cin, sd))
	{
		++m[sd];
	}
	for (um::value_type i : m)
	{
		print(cout, i.first);
		cout << "\t has " << i.second << (i.second > 1 ? " copys" : " copy") << endl;
	}
}

//int main(int argc, const char** argv)
//{
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
