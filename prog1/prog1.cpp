// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<vector>
#include<string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <deque>
#include <forward_list>
using namespace std;
int main() {
	vector<unsigned>v{ 1,2,3,4,5,6,7,8,9 };
	list<unsigned>lst;
	deque<unsigned>dq;
	forward_list<unsigned>fw;
	copy(v.cbegin(), v.cend(), inserter(lst, lst.begin()));
	for (unsigned s : lst) cout << s << " ";
	cout << endl;	lst.clear();
	copy(v.cbegin(), v.cend(), back_inserter(lst));
	for (unsigned s : lst) cout << s << " ";
	cout << endl;	lst.clear();
	copy(v.cbegin(), v.cend(), front_inserter(lst));
	for (unsigned s : lst) cout << s << " ";
	cout << endl;
	cout << endl;
	copy(v.cbegin(), v.cend(), inserter(dq, dq.begin()));
	for (unsigned s :dq) cout << s << " ";
	cout << endl;	dq.clear();
	copy(v.cbegin(), v.cend(), back_inserter(dq));
	for (unsigned s : dq) cout << s << " ";
	cout << endl;	dq.clear();
	copy(v.cbegin(), v.cend(), front_inserter(dq));
	for (unsigned s : dq) cout << s << " ";
	cout << endl;	
	cout << endl;
	//copy(v.cbegin(), v.cend(), inserter(fw, fw.begin()));//forward_list也沒有insert
	//copy(v.cbegin(), v.cend(), back_inserter(fw));//forward_list沒有push_back
	copy(v.cbegin(), v.cend(), front_inserter(fw));
	for (unsigned s : fw) cout << s << " ";
	cout << endl;



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
