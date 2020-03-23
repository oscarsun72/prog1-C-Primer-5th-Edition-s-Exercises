// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<memory>
#include <fstream>
#include"TextQuery.h"
using namespace std;
string make_plural(size_t ctr, const string& word,//頁224
					const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}
ostream& print(ostream& os, const QueryResult& qr)
{
	//如果要找的字有找到，就印出它出現的次數及所有找到的內容
	//os << qr.sought << " occurs " << qr.lines->size() << " "
	//	<< make_plural(qr.lines->size(), "time", "s") << endl;
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << endl;
	//印出所有要找的字詞所在行的內容
	for (auto num : *qr.lines) //處理set中的每個元素
	//避免出現「第0行」這樣的訊息來使人困擾
		os
		<< "\t(line " << num + 1 << ")"
		<< *(qr.file->begin() + num) << endl;
	return os;
}
int main() {
	string fName, strSearch;
	//cout << "請指定要檢索的檔案全名(fullname,含路徑與副檔名)" << endl;
	//if (cin >> fName);
	////必須檢查檔案存不存在	
	//else//若沒有指定檔案的話
	//{
		fName = "V:\\Programming\\C++\\input.txt";
	//}
	//cin.clear();//cin前面已經移動它的迭代器（iterator）了到讀取失敗的位置，故要歸零清除，
	//否則如果這裡讀取失敗，後面的cin >> strSearch判斷就會永遠都是false（讀取失敗）了
	//第103集8：58：00//可參考前面談資料流（stream）的部分
	ifstream ifs(fName);
	TextQuery tq1(ifs);
	//TextQuery tq(tq1);//使用編譯器湊合的拷貝建構器，會將TextQuery的二個成員都複製（拷貝）
	//TextQuery tq=tq1;//使用編譯器湊合的拷貝指定運算子，一樣會將TextQuery的二個成員都複製（拷貝）
	TextQuery* p= new TextQuery(tq1);//使用編譯器湊合的拷貝建構器
	TextQuery tq = *p;//使用編譯器湊合的拷貝指定運算子，拷貝一個副本出來存在tq裡，故當p所指的被清除了，tq依然有效，二者是互不相干的獨立物件
	delete p;//使用TextQuery自行定義的解構器


	while (true) {
		cout << "請輸入檢索字串,或輸入「q」離開" << endl;
		if (!(cin >> strSearch) || strSearch == "q") break;
		QueryResult qr1 = tq.query(strSearch);
		//QueryResult qr(qr1);//使用編譯器湊合的拷貝建構器
		//QueryResult qr=qr1;//使用編譯器湊合的拷貝指定運算子
		QueryResult* p=new QueryResult(qr1);//使用編譯器湊合的拷貝建構器
		QueryResult qr = *p;
		delete p;//使用QueryResult自訂的解構器
		print(cout,qr);
	}
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
