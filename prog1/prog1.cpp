// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
#include<list>
#include<vector>
using namespace std;
int main() {	
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	list<int>lst;
	vector<int>vec;
	for (int i : ia)
	{
		lst.push_back(i); vec.push_back(i);
	}
	list<int>::const_iterator p=lst.cbegin();
	while (p != lst.cend()) {
		if ((*p) % 2)
			p = lst.erase(p);
		else
			++p;
	}
	vector<int>::const_iterator v=vec.cbegin();
	while (v != vec.cend()){
		if ((*v) % 2 == 0)
			v = vec.erase(v);
		else ++v;
	}
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
