// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<vector>
#include<set>
using namespace std;
int main() {
	multiset<string> c ;
	istream_iterator<string>in(cin),end;
	ostream_iterator<string>out(cout, ","); 
	copy(in, end, inserter(c, c.end()));
	vector<string>v;
	copy(in, end, inserter(v, v.end()));
	copy(c.cbegin(), c.cend(), out); cout << endl;
	//copy(v.begin(), v.end(), inserter(c, c.end()));//OK
	//copy(v.begin(), v.end(), back_inserter(c));//Error	C2039	'push_back': is not a member of 'std::multiset<std::string,std::less<_Kty>,std::allocator<_Kty>>'
	//copy(c.begin(), c.end(), inserter(v, v.end()));//OK
	copy(c.begin(), c.end(), back_inserter(v));//OK，與前式同。因vector有push_back()也
	copy(c.cbegin(), c.cend(), out);
	cout << '\n' << "----------" << endl;
	copy(v.cbegin(), v.cend(), out); cout << endl;
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
