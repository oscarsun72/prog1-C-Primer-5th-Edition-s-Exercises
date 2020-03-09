// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。

#include<iostream>
#include<fstream>
#include<string>
#include"TextQuery.h"
using namespace std;
void runQueries(ifstream& infile) {//頁486，引數infile是一個檔案資料流（stream ifstream）代表一個準備作為檢索對象的檔案
	TextQuery tq(infile); //讀入檔案並建置（build）檢索用的map
	// iterate with the user: 提示使用者輸入檢索字詞來進行檢索並印出其檢索結果
	while (true)
	{
		cout << "enter word to look for, or q to quit:";
		string s;
		//如果讀取使用者輸入的字詞失敗（hit end-of-file on the input），或者是使用者輸入了「q」，就中止
		if (!(cin >> s) || s == "q")
			break;
		//執行檢索並印出結果
		print(cout, tq.query(s)) << endl;
	}
}

int main() {
	ifstream ifs(R"(V:\Programming\C++\input.txt)");
	runQueries(ifs);
}



// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
