// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<vector>
#include<string>
//#include<iterator>
using namespace std;
//using std::cout; using std::cin;using std::endl;


void test() {
	char a;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	int tCnt = 0, bCnt = 0, nCnt = 0;
	while (cin>>a)
	{
		switch (a)
		{
			case '\t':
				++tCnt;
				break;
			case '\n':
				++nCnt;
				break;
			case ' ':
				++bCnt;
				break;
			case 'A':
			case 'a':
				++aCnt;
				break;
			case 'E':
			case'e':
				++eCnt;
				break;
			case 'I':
			case'i':
				++iCnt;
				break;
			case 'O':
			case'o':
				++oCnt;
				break;
			case'u':
				++uCnt ;
				break;
			default:
				break;
		}
	}
	cout << aCnt << '\n'
		<< eCnt << '\n'
		<< iCnt << '\n'
		<< oCnt << '\n'
		<< uCnt << '\n'
		<< "blank space:"<<bCnt << '\n'
		<<"tab:" <<tCnt << '\n'
		<<"new line:" <<nCnt << '\n'
		<< endl;
}
	
int main() {

	test();
	return 0;
}

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
