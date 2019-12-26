// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;
//int* p;
//bool b() {
//	p = new int;
//	//int* p = new int;
//	// ...	
//	return p;//沒有delete，則成記憶體耗漏、記憶體洩漏、浪費記憶體了；因為出此範疇，則new所配置的
//	//動態記憶體就無法被清除了。p是不會變成懸置指標（dangling pointer)，因為出此b函式範疇就自動銷毀（自動物件、區域變數）。
//	//return是用傳值的方式（即拷貝），回傳的型別也與p型別不合，但有隱含轉型的關係存在
//	//然而沒有delete，尤其在此例，既然要回傳指標p，就不能delete p；應該是將local p的回傳給另一個指標，以對p原所指向的動態配置的物件，可以有後續操作，包括將其delete
//	//否則，就是將p已成公用物件，而非區域物件
//}
//以上是以公用物件來改寫p
//以下則是另用一個指標來接管p原指向的動態配置的物件（dynamically allocated object）
int* b() {
	int* p = new int;
	//int* p = new int;
	// ...	
	return p;//沒有delete，則成記憶體耗漏、記憶體洩漏、浪費記憶體了；因為出此範疇，則new所配置的
}
int main() {
	int* q = b();
	if (q == 0) cout << "p 沒有指向任何物件" << endl;
	else {
		cout << q << endl;
		cout << *q << endl;
	}
	//if (b() == 0) cout << "p 沒有指向任何物件" << endl;
	//else cout << b() << endl;
	////delete p;
	delete q;
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
