// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<memory>

using namespace std;
vector<string>vs;
map<string, set<size_t>>mpWord_lineNum;
map<string, set<size_t>>::iterator mpIter;

void qureyData(ifstream& ifs) {//配置好檢索資料
	string wordLine;
	size_t lineNum(0);
	while (!ifs.eof() && getline(ifs, wordLine))
	{
		vs.push_back(wordLine);
		lineNum++;
		istringstream is(wordLine);
		string word;
		while (is >> word)
		{
			mpIter = mpWord_lineNum.find(word);
			if (mpIter == mpWord_lineNum.end()) {
				set<size_t>st_lineNum;
				st_lineNum.insert(lineNum);
				mpWord_lineNum.insert(make_pair(word, st_lineNum));
			}
			else//若map中已有此字
				mpIter->second.insert(lineNum);
		}
	}
}
void query(string& searchWord) {
	mpIter = mpWord_lineNum.find(searchWord);
	if (mpIter == mpWord_lineNum.end())
	{
		cout << "沒有找到\"" << searchWord << "\"字！" << endl;
	}
	else
	{
		size_t s = mpIter->second.size();
		cout << endl;
		cout << searchWord << " occurs " << s << ((s > 1) ? " times" : " time") << endl;
		for (size_t s : mpIter->second)
			cout << "\t(line " << s << ") " << vs[s] <<endl;		
		cout << endl;
	}
}

int main() {
	string strSearch;
	cout << "請指定要檢索的檔案全名(fullname,含路徑與副檔名)" << endl;
	if (cin >> strSearch);
	//必須檢查檔案存不存在	
	else//若沒有指定檔案的話
	{
		strSearch = R"(V:\Programming\C++\input.txt)";//"V:\\Programming\\C++\\input.txt";
	}
	ifstream ifs(strSearch);
	qureyData(ifs);
	cin.clear();
	while (true)
	{
		cout << "請輸入檢索字串,或輸入「q」離開" << endl;
		if (!(cin >> strSearch) || strSearch == "q") break;
		query(strSearch);
	}
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
