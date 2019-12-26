// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;

int main() {
	int* q = new int(42), * r = new int(100);
	r = q;//因為r現在不再指向new出來的int(100)，這個int(100)沒有delete掉，就成了記憶體耗漏、記憶體外洩
	//int(42)現在則有二個指標指向它，這些指標就有淪為懸置指標（dangling pointer)的危險
	auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
	r2 = q2;//r2原來指向的動態配置的「<int>(100)」因為沒有指向它的智慧指標，就隨之銷毀了
	//「<int>(42)」這個動態配置物件則會有兩個智慧指標指向它
	//q2.use_count=2,r2.use_count=0---印出來卻是2！因為r2現在等於q2了。r2.use_count=2是表示除了r2以外，還有q2也指向同一個動態配置物件
	//因此，所謂的參考計數（reference count），應當時屬於物件的屬性，而不是智慧指標的！
	//一個動態配置的物件有多少參考計數，就表示它有多少智慧指標指著它。英文版好像也弄錯了
	cout << q2.use_count()<< endl;
	cout <<r2.use_count() << endl;
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
