// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;
void test(int* q)
	{ //新的區塊
	//這是未定義的：因為兩個各自定義的shared_ptr卻指向相同的記憶體位址
		shared_ptr<int>r(q);
		cout << r.use_count() << endl;//此時r的參考計數是1，雖然r、q、p都指向了相同的動態物件
	}// 當區塊結東，「 shared_ptr<int>(q)」（用q來初始化創建的shared_ptr<int>會被摧毁，當它摧毀時，因為它是獨立於p的，所以參考計數是1，摧毀後成了0，所以，會調用delete來刪除它所指向的物件，這個物件也是q所指向的，所以q指向的記憶體位址就會被釋放
	// block ends, q is destroyed, and the memory to which q points is freed
int main() {	
	shared_ptr<int> p(new int(42)); // 此時p所指的動態物件其參考計數是 1
	int* q = p.get(); //將q作為儲存p.get()回傳值的變數是ok的，但決定不要在可能刪除q所指物件的情境下用到這個q（don't use q in any way that might delete its pointer）
	test(q);
	int foo = *p; //這是未定義的；因為p所指的記憶體已被區塊中的shared_ptr<int>釋放了
	//此例當即為 p與q與shared_ptr<int>三者共享了int(42)這個記憶體資源
	//foo到底是什么意思？ https://www.zhihu.com/question/34512213
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
