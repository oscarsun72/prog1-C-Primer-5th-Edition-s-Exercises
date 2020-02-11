// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<fstream>
#include<sstream>
#include<iterator>
#include<map>
#include<string>
using namespace std;
int main() {
	map<string, string>mReplace;
	ifstream ifs("V:\\Programming\\C++\\exercise11_34transformRule.txt");
	ifstream ifsInput("V:\\Programming\\C++\\exercise11_34input.txt");
	istream_iterator<string>in(ifs), end;
	string key, value;
	while (in != end) {
		key = *in; getline(ifs, value);
		if (value.size() > 1)
			mReplace.insert(make_pair(key, value.substr(1)));
		else
			throw runtime_error("沒有轉換規則！");
		++in;
	}
	map<string, string>::const_iterator mIt;
	string ocr, transformedLine;
	while (getline(ifsInput, transformedLine)) {
		istringstream iss(transformedLine);
		istream_iterator<string>input(iss), e, wPos;
		bool wLast = false;
		while (input != e)
		{
			ocr = *input;
			wPos = ++input;
			if (wPos == e) wLast = true;
			mIt = mReplace.find(ocr);
			if (mIt != mReplace.cend())
				cout << mIt->second << ((wLast) ? "" : " ");//利用條件運算子（頁151）判斷是否是本行最後1個字，是，就不再後綴半形空格
			else
				cout << ocr << ((wLast) ? "" : " ");
			//cout << mReplace[ocr] << ((wLast)?"":" ");//下標運算子
			/*用下標運算子的結果：
				are you
				why  you    picture
				okay? thanks! later
			原本規則沒有字就會被取代為空字串*/
		}
		cout << endl;
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
