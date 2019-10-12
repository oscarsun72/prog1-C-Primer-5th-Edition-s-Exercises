// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void biggies(vector<string>& vecStr,vector<string>::size_type sz ) {
	//因為要對vecStr做編輯（sort演算法都會動到容器元素），所以不能是對常值的參考:
	//const vector<string>& vecStr
	sort(vecStr.begin(), vecStr.end());
	stable_sort(vecStr.begin(), vecStr.end()
				, [](const string& s1, const string & s2) {return s1.size()<s2.size();});
	auto iterB = find_if_not(vecStr.cbegin()
				, vecStr.cend(), [sz](const string& s) {return s.size()<sz; });
	for_each(iterB, vecStr.cend(), [](const string& s) {cout << s << endl; });
}
int main() {
	vector<string> vec;
	string word;
	while (cin>>word)
	{
		vec.push_back(word);
	}
	biggies(vec,8);
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
