// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<memory>
#include <fstream>
#include"TextQuery.h"
#include"QueryResult.h"
using namespace std;

pair<shared_ptr<vector<string>>, shared_ptr<map<string, set<size_t>>>> queryData(ifstream& infile)
{
	string lStr;
	size_t line_Num{ 0 };
	vector<string>vs;//主要就是這兩個（vector、map）容器要作為TexQuery與QueryResult資源共享者
	map<string, set<size_t>>word_lineNum;
	/*用了make_shared函式，就已經動用到了動態記憶體區了：
	這個函式會在動態記憶體區中配置並初始化（即建置）一個物件，然後回傳一個shared_ptr指向該物件。和智慧指標一樣，make_shared也是定義在memory標頭檔中。(頁451）
	而shared_ptr類別是會保證只要還有任何的shared_ptr依附在那個記憶體上，那個記憶體就不會被釋放。（頁454）
	https://play.google.com/books/reader?id=J1HMLyxqJfgC&pg=GBS.PT842.w.7.0.42
	*/
	shared_ptr<vector<string>>spVs(make_shared<vector<string>>(vs));//利用智慧指標shared_ptr來達到
	shared_ptr<map<string, set<size_t>>>spWord_lineNum(
		make_shared<map<string, set<size_t>>>(word_lineNum));//資源共用的目的
	while (infile && !infile.eof())//第98集6:46:00
	{
		getline(infile, lStr);
		spVs->push_back(lStr);//one line of text in an element		
		++line_Num;
		istringstream isstr(lStr);
		string word;
		while (isstr >> word)
		{
			map<string, set<size_t>>::iterator mIter = spWord_lineNum->find(word);
			if (mIter == spWord_lineNum->end()) {//如果文字行號的map還沒有此文字的話
				set<size_t> line_num_st;
				line_num_st.insert(line_Num);
				spWord_lineNum->insert(make_pair(word, line_num_st));
			}
			else//如果文字行號的map已經有此文字的話
				mIter->second.insert(line_Num);//若原已有此行號，用insert就不會插入（何況set本來鍵值（就是「值」）就不能重複
		}
	}
	return make_pair(spVs, spWord_lineNum);
}

int main() {
	string fName, strSearch;
	fName = "V:\\Programming\\C++\\成品\\cj5.txt";
	cin.clear();//cin前面已經移動它的迭代器（iterator）了到讀取失敗的位置，故要歸零清除，
	//否則如果這裡讀取失敗，後面的cin >> strSearch判斷就會永遠都是false（讀取失敗）了
	//第89集1：4：00//可參考前面談資料流（stream）的部分
	ifstream ifs(fName);
	TextQuery tq(queryData(ifs));
	while (true) {
		cout << "請輸入檢索字串,或輸入「q」離開" << endl;
		if (!(cin >> strSearch) || strSearch == "q") break;
		QueryResult qr = tq.query(strSearch);
		qr.print();
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
