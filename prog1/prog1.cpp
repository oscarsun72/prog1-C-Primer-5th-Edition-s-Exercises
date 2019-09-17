// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


//#include"prog1.h"
//#include "Chapter6.h"//標準程式庫才用角括弧
//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include <iostream>
using namespace std;
class Debug {
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) {
	}
	constexpr Debug(bool h, bool i, bool o) :
		hw(h), io(i), other(o) {
	}
	constexpr bool any() { return hw || io || other; }
	constexpr void set_io(bool b) { io = b; }
	constexpr void set_hw(bool b) { hw = b; }
	constexpr void set_other(bool b) { other= b; }//原作「hw = b;」
private:
	bool hw; // hardware errors other than IO errors
	bool io; // IO errors
	bool other; // other errors
};


int main() {
 Debug io_sub(false, true, false); // debugging IO
//有「constexpr」還會出錯：「E1086	the object has type qualifiers that are not compatible with the member function "Debug::any"	」下同。 
 io_sub.set_hw(true); 
 io_sub.set_io(true);
 io_sub.set_other(true);
if (io_sub.any()) // equivalent to if(true)
cerr << "print appropriate error messages" << endl;
Debug prod(false); // no debugging during production
if (prod.any()) // equivalent to if(false)
cerr << "print an error message" << endl;
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
