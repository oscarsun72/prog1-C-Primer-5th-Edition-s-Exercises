// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;

int main() {	
	int ix = 1024, * pi = &ix, * pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	//IntP p0(ix);//(a) ：不能直接用int來初始化
	IntP p2(pi2);//(c) ：要用new回傳的pointer
	//IntP p1(pi);//(b)竟然連普通取址運算子回傳的指標也可以。只有在編撰時才行；若執行，仍會出錯！
	//IntP p3(&ix);//(d)和(b)是一樣的：prog1.exe has triggered a breakpoint.occurred
	//IntP p4(new int(2048));//(e)和(c)一樣
	IntP p5(p2.get());//(f) 和(b)(d)是一樣的,因為p2.get()回傳的是一般指標，不會new回傳的指標：prog1.exe has triggered a breakpoint. occurred
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
