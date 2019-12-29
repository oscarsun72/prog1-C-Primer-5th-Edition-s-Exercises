// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;


void process(shared_ptr<int> ptr)
{
	//cout << sp.use_count() << endl;
	//使用ptr
} // ptr超疇出範疇，並被摧毁了

int main() {
auto p = new int(1);
auto sp = make_shared<int>(1);
	//cout << sp.use_count() << endl;
	process(sp);//(a)legal，sp參考計數（reference count）會加1，proecss結束後減1。然而
	//如練習12.10，若process內的區域智慧指標結束，要注意防止sp成為懸置指標（dangling pointer）
	// sp並非區域的，所以不會隨出process範疇而被摧毀。且process內的區域智慧指標雖在process結束後摧毀，但與sp指向同一個記憶體位置，該位置物件仍有sp指向它，故雖然proecss區域的智慧指標摧毀了，也不會釋放該物件之記憶體。
	//cout << sp.use_count() << endl;
	cout << "*sp=" << *sp << endl;	
	cout << "*p=" << *p << endl;//p所指之記憶體已被釋放，p成了懸置指標（dangling pointer)

	//(b)process(new int());//illegal，因為型別不合，不具隱含轉型。new回傳的是一個普通指標、內建指標，而不是智慧指標shared_ptr
	//(c)process(p); //illegal，同前
	//(d)process(shared_ptr<int>(p)); //和（a）類似。這裡是將p所指向的物件操縱權交給了process內區域智慧指標，p，就合該無法再對其物件作操作了，p當設為空指標，以免淪為懸置指標。參見Table 12.3. Other Ways to Define and Change shared_ptrs 表12.3 :定義和變更shared_ptr的其他方式：shared_ptr<T>p(q)
	//此例中shared_ptr乃區域性的，故會被銷毀，而使p無效，成為懸置指標。

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
