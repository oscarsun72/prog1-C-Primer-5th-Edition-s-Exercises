// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<map>
#include<vector>
using namespace std;
int main() {
	vector<int>v{ 1,2 };
	map<string, vector<int>>m;
	m["孫守真"] = v;
	istream_iterator<string>in(cin), end;
	while (in != end)
		m.insert(make_pair(*in++, v));
	string s("守真");
	map<string, vector<int>>::iterator it = m.find(s);
	map<string, vector<int>>::iterator itL = m.lower_bound(s);
	map<string, vector<int>>::iterator itU = m.upper_bound(s);
	pair<map<string, vector<int>>::iterator, map<string, vector<int>>::iterator>
		itE = m.equal_range(s);
	if (itL == itE.first)
		cout << "lower=first" << endl;
	if (itU == itE.second)
		cout << "upper=second" << endl;
	if (itL == itU)
		cout << "not found" << endl;
	if (itE.first == itE.second)
	{
		cout << "not found" << endl;
		cout << (itE.first)->first << endl;//可見可插入位置也如前循序容器的insert都是在前位插入要插入的元素
		m.insert(itE.first, make_pair(s, v));
	}
	decltype(m.cbegin()) itM = m.cbegin();
	while (itM != m.cend())
	{
		cout << itM++->first << endl;
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
