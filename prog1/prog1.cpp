// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<list>
//#include<algorithm>
using namespace std;
void elimDups(list<string>& words)
{
	// sort words alphabetically so we can find the duplicates
	//sort(words.begin(), words.end());
	words.sort();//用list版本的演算法，在unique前一樣要先排序
	// unique reorders the input range so that each word appears once in the
	// front portion of the range and returns an iterator one past the unique range
	//auto end_unique = unique(words.begin(), words.end());
	words.unique();//因為list成員函式演算法是直接對list動手的，所以不必再用erase
	// erase uses a vector operation to remove the nonunique elements
	//words.erase(end_unique, words.end());
	//words.erase();
}
int main() {
	list<string>lst;
	istream_iterator<string>in(cin), end;	
	copy(in, end, back_inserter( lst));
	elimDups(lst);
	ostream_iterator<string>out(cout," ");
	copy(lst.cbegin(), lst.cend(), out);
	cout << endl;
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
