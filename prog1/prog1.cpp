// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<memory>
#include <vector>

using namespace std;

int main() {
	size_t n; vector<string>vs;
	allocator<string>alloc;
	//string* const p = new string[n]; //建構n個空的string字串（預設初始化）
	
	string s;
	//while (cin >> s && q != p + n) //「cin>>s」：讀取標準輸入到s
	while (cin >> s ) 
		vs.push_back(s);
	n = vs.size();
	//p要在最後delete或destroy作為引數傳入，才能清除動態陣列，故p不能更動，才為const p
	string* const p = alloc.allocate(n); //配置n個未初始化的string原生記憶體空間block（區塊、記憶體區塊）
	//	*q++ = s;              //將一個新值（=s）指定給q指向的元素
	//string* q = p; //q指向了p動態陣列中的第1個字串元素	
	string*q=uninitialized_copy(vs.cbegin(), vs.cend(), p);
	//const size_t size = q - p; //記下已經讀取了多少個動態陣列p中的字串元素
	const size_t size = q - p;
	if (size==n)
	{
		cout << "size==n" << endl;
	}
	//……
	//對這個動態陣列的使用
	q = p;
	while (q != p + n)
		cout<<*(q++)<<",";//++優先權比*高，加不加()是一樣的
	cout << endl;
	//delete[] p; //因為普通常值（恆定）指標（內建型別為對string的指標）p指向的是一個動態陣列，所以對它delete必須加上[]空的方括號
	alloc.destroy(p);
	alloc.deallocate(p,n);//摧毀解構後別忘了釋放（解配置） 第88集 3：26：40
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
