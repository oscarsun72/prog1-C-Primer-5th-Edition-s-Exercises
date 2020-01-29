// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<list>
#include<map>

using namespace std;
int main() {
	typedef list<int>::iterator liIter;
	multimap<liIter,int>m;
	list<int>li;
	istream_iterator<int>isi(cin), end;
	while (isi!=end)
	{
		li.push_back(*isi++);
	}
	liIter lii=li.begin();
	for (int i : li)
	{
		//map在加入新元素時一定要「隨機」比對鍵值！
		//m[lii] = i;//list的迭代器沒有隨機存取的！當然就不能進行下標運算來作比對
		m.insert(make_pair(lii, i));//map此式也是不行,multimap也不行
		lii++;
	}	
	ostream_iterator<int>out(cout, ",");
	for (auto a : m)
	{
		cout << *a.first << ":\t";
		out++=a.second;
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
