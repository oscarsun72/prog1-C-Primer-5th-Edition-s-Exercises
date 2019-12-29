// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;
// ptr會在process被呼叫時創建並初始化
void process(shared_ptr<int> ptr)
{
	//使用ptr
	cout << "ptr.use_count="<<ptr.use_count() << endl;
} // ptr超出範疇，並被摧毁了

int main() {
	shared_ptr<int> p(new int(42));
	cout << "p.use_count=" << p.use_count() << endl;
	process(shared_ptr<int>(p.get()));
	//process執行完成後，p會變成懸置指標!
	//cout << "p.use_count="<<p.use_count() << endl;//對懸置指標做任何事情，都是錯誤;連對它指定assign為nullptr也會出錯
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
