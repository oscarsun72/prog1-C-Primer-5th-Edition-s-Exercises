// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;

shared_ptr<int>pp(new int(3));
void process()
{
	int* r = new int(10);
	shared_ptr<int> ptr(r);//此時「10」這個動態物件有 普通指標r、智慧指標ptr兩個指標指向它
	int* q = new int(2);
	cout << "*ptr=" << *ptr << endl;
	cout << "ptr計數" << ptr.use_count() << endl;
	cout << "pp計數" << pp.use_count() << endl;
	ptr.reset(q);//此時普通指標r指向的「10」會被智慧指標ptr摧毀，r就淪為懸置指標（dangling pointer)，一個活死人（活屍）
	if (q == nullptr)//q仍指向「2」，不會是空指標
		cout << "yes:q == nullptr" << endl;
	cout << "*ptr=" << *ptr << endl;
	cout << "ptr計數" << ptr.use_count() << endl;
	cout << "*q=" <<*q << endl;
	r = nullptr;//這樣r就不再是懸置指標了，而是一個空指標	
}

int main() {	
	process();
	cout << "*pp="<<*pp << endl;
	cout << "pp計數="<<pp.use_count() << endl;
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
