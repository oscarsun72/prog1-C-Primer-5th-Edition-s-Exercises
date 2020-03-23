// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
#include<iostream>
using namespace std;

struct Employee {
//public:
	Employee() :ID(++myID),employeeName("十方三世佛，共同一法身，一心一智慧，力無畏亦然"){};
	Employee(const string& employeeName) :ID(++myID),employeeName(employeeName) {};
	Employee(const Employee& e) :ID(e.ID),employeeName(e.employeeName) {};
	//string employeeName;
	//unsigned ID;
	const string employeeName;
	const unsigned ID;
private:
	static unsigned myID;//此類似宣告-配置資源（宣告類別內的靜態成員）
	//可見static成員因不屬於物件所有，所以在拷貝控制成員操作時，並不會受到影響
};
unsigned Employee::myID = 0;/*此類似定義-建構實例，初始化已經宣告的類別靜態成員
							如何初始化靜態資料成員
							https://openhome.cc/Gossip/CppGossip/staticMember.html
							static 資料成員屬於類別，而非個別實例，想在類別內初始 static 資料成員的話，必須是個 constexpr，也就是必須是編譯時期常數，若否，必須在類別外指定，例如：
							class Math {
							public:
								static double PI;
							};
							double Math::PI = 3.14159;
							*/

void f(Employee s) { cout << s.employeeName << "'s ID is :"<< s.ID << endl; }
int main() {	
	Employee a,b("孫守真"),c("阿彌陀佛");
	//f(a);f(b); f(c);
	Employee d(c),e;
	//e = b;
	Employee fe;
	f(d); f(e); f(fe);
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

