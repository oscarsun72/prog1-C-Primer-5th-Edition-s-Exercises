// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<memory>

using namespace std;

int main() {
	string s;//當輸入的資料長過動態配置的陣列大小時，可以輸入儲存，但在delete[]時卻會出錯
	cin >> s;
	//size_t sz = s.size()-1;
	size_t sz = s.size();
	unique_ptr<char[]>up(new char[sz]);//size回傳的非常值，故可應付動態長度的資料輸入
	for (size_t i = 0; i != sz; ++i)
		up[i] = s[i];
	cout <<up<< endl;
	for (size_t i = 0; i != sz; ++i)
		cout<<up[i]<<",";
	cout << endl;
	//delete [] up.get();//當輸入的資料若大過陣列能接受的範圍這樣也是沒有用的。[]中指定陣列大小也無用
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
