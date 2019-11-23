// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;


auto p = new int(1);
auto sp = make_shared<int>(1);
void process(shared_ptr<int> ptr)
{
	//cout << sp.use_count() << endl;
	//使用ptr
} // ptr超疇出範疇，並被摧毁了

int main() {
	//cout << sp.use_count() << endl;
	process(sp);//legal，sp參考計數（reference count）會加1，proecss結束後減1。然而如練習12.10，若process內的區域智慧指標結束，要注意防止sp成為懸置指標（dangling pointer）
	//cout << sp.use_count() << endl;
	cout << *sp << endl;
	process(shared_ptr<int>(p)); //和（a）類似。這裡是將p所指向的物件操縱
	cout << *p << endl;//p所指之記憶體已被釋放，p成了懸置指標（dangling pointer)
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
