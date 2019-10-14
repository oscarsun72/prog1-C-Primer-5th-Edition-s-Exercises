// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;//若沒此行，則「_1」就undefined
bool isShorterthe(const string& s, string::size_type sz) {
	return s.size() <= sz;
}
bool check_size(const string& s, string::size_type sz) {
	return s.size() >= sz;
}

int main() {
	vector<string>v;
	string w;
	unsigned sz=6;
	while (cin >> w)
		v.push_back(w);
	auto b = bind(isShorter, _1, sz);
	cout<<count_if(v.cbegin(), v.cend(), b)<<endl;//此3種均可以，此題不用lambda
	//可見在呼叫這個b （new callable 可呼叫物件 callable object）不用加呼叫運算子（call operator），也不必傳遞引數
	//cout<<count_if(v.cbegin(), v.cend(), bind(isShorter, _1, sz))<<endl;
	//cout<<count_if(v.cbegin(), v.cend(), [](const string& s)->bool {return s.size() <= 6; })<<endl;
	
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
