// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>//for「istream_iterator」
#include<deque>
#include<algorithm>//for sort()、unique_copy()
using namespace std;
int main() {
	istream_iterator<int>i(cin),end;
	deque<int>dq(i,end);//i用cin建構初始化，因為cin現在是空的，沒有元素，所以i一定時和end相等的，同時指著第一和最後的「元素」。
	sort(dq.begin(), dq.end());//汰重前一定要排序,由此亦可知unique演算法是什麼「演算」（推演、計算）的了
	ostream_iterator<int>o(cout, ",");
	unique_copy(dq.begin(),dq.end(),o);
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
