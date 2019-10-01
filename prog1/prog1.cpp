// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
#include<string>
#include<vector>
#include<list>
#include<iostream>
using namespace std;
string compareElements(list<int>lsti, vector<int> veci) {
	if (lsti.empty() || veci.empty()) return "請傳入有效容器！";
	vector<int>::size_type sz{0};
	for (int var : lsti) {
		if (var > veci[sz])
			return "list 大於 vector";
		else if (var < veci[sz])
		{
			return "list 小於 vector";
		}
		else
		{
			++sz;
			if (sz > (veci.size() - 1))
				if(lsti.size() !=veci.size())
					return "list 元素多於 vector,且vector是list的初始子序列（initial subsequence）";
				else
					return "list 等於 vector";
		}
	}
	if (lsti.size()<veci.size())
	{
		return "list 是 vector的初始子序列（initial subsequence）";
	}
	else
		return "list 等於 vector";	
}

int main() {
	list<int>lsti{2,3,4,4,5};
	vector<int>veci2{2,3,4,4,5};
	cout<<compareElements(lsti, veci2)<<endl;
}



//int main(int argc, const char** argv)
//{
//	print_sum_of_the_elements_in_the_list({ 11,2,3 });
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
