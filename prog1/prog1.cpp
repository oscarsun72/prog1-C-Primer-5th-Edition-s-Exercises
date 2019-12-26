// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<vector>
//#include<new>
using namespace std;
vector<int>* returnDynamicallyAllocatedVec() {
	return new(vector<int>);
}

void read_give_values_to_the_elements(vector<int>* vp){
	istream_iterator<int>in(cin), end;
	while (in!=end)
	{
		vp->push_back(*in++);
	}
}
void print_the_values_that_were_read(vector<int>* vp) {
	ostream_iterator<int>out(cout, ",");
	for (int i :*vp)
	{
		*out++=i;
	}
}

int main() {
	vector<int>* vp = returnDynamicallyAllocatedVec();
	read_give_values_to_the_elements(vp);
	print_the_values_that_were_read(vp);
	delete vp;
	vp = nullptr;//這一行在此例中應是可有可無。因為應用程式馬上就結束了。自然也會釋放它的所有記憶體資源；但若沒有如此，就必須有此行，這樣vp才不會淪為懸置指標（dangling pointer)
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
