// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
#include<string>
class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& ) :ps(new std::string(*ps)),i(i){}//拷貝建構器
	HasPtr& operator=(const HasPtr&); //拷貝指定運算子
	~HasPtr() {};//解構器（destructor）
private:
	std::string* ps;
	int i;
};
HasPtr& HasPtr::operator=(const HasPtr&rhH)
{
	i = rhH.i;
	*ps = *rhH.ps;
	return *this;
}

int main() {
	HasPtr hp;	
	HasPtr hp2("守真"),hp1(std::string("阿彌陀佛"));	
	hp = hp1;
	hp1 = hp2;
	HasPtr* p = new HasPtr("南無阿彌陀佛");
	delete p;
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

