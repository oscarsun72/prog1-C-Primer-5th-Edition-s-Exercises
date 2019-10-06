// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
#include<vector>
using namespace std;
int main() {
	vector<int>v = { 1,2,3,4,5 };
	// disaster: the behavior of this loop is undefined
	auto begin = v.begin(),
		end = v.end(); // bad idea, saving the value of the end iterator
	// safer: recalculate end on each trip whenever the loop adds/erases elements
	while (begin != v.end()) {
		// do some processing
		++begin; // advance begin because we want to insert after this element
		//begin = v.insert(begin, 42); // insert the new value
		v.insert(begin, 42); // insert the new value
		++begin; // advance begin past the element we just added
		//插入元素(尤其vector string deque）begin()回傳的迭代器可能會失效
		//在此例中，begin失效了
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
