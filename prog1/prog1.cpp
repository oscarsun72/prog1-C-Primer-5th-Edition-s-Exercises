// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
//#include "Sales_data.h"

	//const char* a[4] = { "", "V:\\Programming\\C++\\1.txt"
	//	, "V:\\Programming\\C++\\2.txt", "V:\\Programming\\C++\\3.txt" };
//#include <iostream>
#include<vector>
#include<string>
#include <iostream>
#include<algorithm>
using namespace std;

void print(vector<string>& vec) {
	for (string s : vec)
		cout << s << ",";
}
inline bool isShorter(const string & s1,const string & s2) {
	return s1.size() < s2.size();
};
void elimDups(vector<string>& vecStr) {
	print(vecStr); cout << endl;
	sort(vecStr.begin(), vecStr.end());//也不能用const iterators
	print(vecStr); cout << endl;
	auto rngEnd = unique(vecStr.begin(), vecStr.end());//因為unique會overwrite所以不能用「cbegin()、cend()」
	print(vecStr); cout << endl;
	vecStr.erase(rngEnd, vecStr.cend());
	print(vecStr); cout << endl;
	stable_sort(vecStr.begin(), vecStr.end(), isShorter);//通常我們呼叫函式是必須要傳引數，而在這裡卻只要調用其名稱即可！
	print(vecStr); cout << endl;
}
int main() {
	string word; vector<string> vecStr;
	while (cin >> word) {
		vecStr.push_back(word);
	}
	elimDups(vecStr);
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
