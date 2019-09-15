// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//#include"prog1.h"
//#include "Chapter6.h"//標準程式庫才用角括弧
//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
//#include "Sales_item.h"//自訂的標頭檔則用雙引號
//#include "Sales_data.h"
//#include "Person.h"
//#include "Screen.h"
//#include<string>
#include<vector>
#include <iostream>
using namespace std;
class NoDefault {
	int iMem;
	NoDefault() :iMem(0) { cout << "預設建構器（default　constructor）" << endl; }
public:
	NoDefault(int  i) :NoDefault() { cout << "int" << endl; }	//用委派達到類似預設建構器（default constructor）的功能
	inline int iMemR() { return iMem; }
};

class c
{
public:
	c()=default;
	~c();//解構器
	inline int ndVal() { return nd.iMemR(); }
private:
	NoDefault nd;
};

c::~c()
{
	nd = NULL;
}


int main() {
	vector<c> vec(10);
	//c cTest;
	//cout<< cTest.ndVal() <<endl;//should be 0
	for(c i:vec)
		cout << i.ndVal() << endl;//should be 0
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
