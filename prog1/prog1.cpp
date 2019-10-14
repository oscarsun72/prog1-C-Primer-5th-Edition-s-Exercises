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
using namespace std;
int main() {
	list<string>lst;	
	vector<string>v;// {"戒", "定", "慧", "戒"};
	string w;
	while (cin >> w)		v.push_back(w);
	//不排序就無法正確汰重
	sort(v.begin(),v.end());
	//以下三者均可，唯front_inserter結果元素是倒序
	unique_copy(v.begin(), v.end(), front_inserter(lst));
	//unique_copy(v.begin(	), v.end(), back_inserter(lst));
	//unique_copy(v.begin(), v.end(), inserter(lst,lst.begin()));
	for (string s : lst) cout << s << " ";
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
