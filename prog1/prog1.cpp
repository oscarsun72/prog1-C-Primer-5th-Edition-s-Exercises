// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;

int main() {
	auto sp = make_shared<int>(1);
	auto p = sp.get();
	//sp.reset(p);//這也會出錯！大概是不能用sp本身get出來的普通指標來作reset引數；
	//或reset引數的指標必不能與sp指向同一個記憶體位址？非也！
	//因「如果p是指向其物件的唯一一個shared_ptr，reset會摧毀其物件。」在此例reset會摧毀sp
	//所指之物件，故在測試中sp與p在reset後同時失效－－成了懸置指標，故後續執行會出錯
	//delete p;//會使用sp成了懸置指標，執行時也會出錯。此行當改用下式來釋放p
	sp = nullptr;//此時p成了懸置指標
	p = nullptr;//此時p成了空指標
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
