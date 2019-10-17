// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
int main() {
	vector<int>v{1,2,3,0,4,11,3,5,2,0};			
	list<int>lst(7-(3-1));//the elements from positions 3 through 7
	//copy的目的地容器要有和copy來源的容器至少有一樣的size()
	copy(v.crbegin() + (v.size() - 7), v.crbegin() + (v.size() - 2), lst.begin());	
	ostream_iterator<int> oIter(cout, ",");
	/*copy(v.crbegin() + (v.size() - 7), v.crbegin() + (v.size() - 2),oIter); cout << endl;
	copy(v.cbegin() + 2, v.cbegin() + 6,oIter); cout << endl;
	cout << endl; copy(v.cbegin() , v.cend() ,oIter); cout << endl;	*/
	copy(lst.cbegin(), lst.cend(),oIter);cout << endl;
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
