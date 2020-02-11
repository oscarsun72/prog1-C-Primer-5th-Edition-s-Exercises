// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<fstream>
#include<iterator>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
	//計算各個字彙出現的頻率，但是這些字彙並不會按照字母順序來排列
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word)
		//	++word_count[word];          //提取並遞增word的字頻數
	{
		(word_count.count(word)) ? word_count.insert({ word, ++word_count[word] }) 
			: word_count.insert({ word,1 });
	}
	for (const auto& w : word_count) //將map中的每個元素印出來
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
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
