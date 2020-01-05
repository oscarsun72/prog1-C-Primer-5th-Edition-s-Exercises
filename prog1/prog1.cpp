// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<memory>

using namespace std;


int main() {
	allocator<string> alloc;/*宣告、定義一個allocator型別物件，它可以配置出一個存放string型別的記憶體資源（區塊）
									object that can allocate strings*/
	size_t n = 10;
	auto const p = alloc.allocate(n); //用alloc這個allocator型別物件來配置n個未經建構（unconstructed應即是未經初始化）的字串。

	auto q = p;  //q指標會指向最後一個被建構出來的元素後面的位置//此處決定有錯！英文版中文版均然。p應是指向allocate(n)配置出來的第一個元素，q才是指向最後一個元素後的位置，然auto q=p,用p將q初始化，不就是q=p了！
	//第87集7：31:00原來這裡以下3行是分別表述的，只能擇一，不能連貫！
	//3個都是q推進一個位置，故曰是「指向最後一個被建構出來的元素後面的位置」
	//以下3行錯在是解參考p不是解參考q！英文版誤p為q！
	//alloc.construct(q++);//解參考（dereference）q就會得到一個空的string字串
	//alloc.construct(q++, 10, 'c'); //解參考q就會是一個10個c的字串字面值（string literal）（或string字串。因為是用string的建構器來建構的10個c的字串）
	//alloc.construct(q++, "hi"); //解參考q得到的是一個"hi"字串，乃是由string建構器構成的。
	//要改成前綴版本，才能印出解參考q，並且後面destroy也要改成後綴版本，才不會出錯（誤刪空指標）
	alloc.construct(++q, "hi"); //解參考q得到的是一個"hi"字串，乃是由string建構器構成的。

	//cout << *p << endl; //可以：使用了string的輸出運算子（output operator）
	cout << *q << endl; //阿災（災難，但實際在Visual Studio 2019此項並不會出錯！）：q指向的是一個未經建構的記憶體區塊（就是q指向了一個不存在的物件，類似或等同於懸置指標）
	//q在此情形下是非null的、未初始化的指針，類似懸置指標（dangling pointer），並沒有指向一個實存的物件。

	while (q != p)
		//alloc.destroy(--q); //釋放那些已經配置給string
		alloc.destroy(q--); //釋放那些已經配置給string

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
