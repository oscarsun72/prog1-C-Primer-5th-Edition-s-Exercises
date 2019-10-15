// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<fstream>
#include<iterator>//for「istream_iterator」
#include<string>
#include<vector>
using namespace std;
int main() {
	ifstream ifstm("V:\\Programming\\C++\\3.txt");
	//在Visual Studio預設情況下，文字檔僅支援ANSI或Big5編碼。UTF-8應該是要用到轉碼功能
	istream_iterator<string>inf(ifstm), endf;
	vector<string>v(inf,endf);//是迭代器（iterator）的話就可以直接用首尾二個迭代器來指出要建構元素的範圍及其值
	//凡是用到迭代器範圍的通常都是要巡覽該範圍內元素一遍的，所以這個迭代（iterate）或巡覽，就是交由vector的建構器（constructor）來執行吧
	//才可以看似不用寫迴圈，卻能不斷執行、迭代、巡覽若此
	ostream_iterator<string>outf(cout," ");
	//沒有#include<algorithm> 卻能用copy，也是一絕。應與已經「using namespace std;」有關
	copy(v.cbegin(), v.cend(), outf);//一樣是指出了「迭代器範圍」然後巡覽（迭代（iterate））每個範圍內的元素，到outf上頭
	//所以巡覽（迭代（iterate））的工作是由用到這個迭代器範圍引數的函式、建構器或演算法等來負責的
	/*以上寫法比以下精簡多了 詳頁406上方：
	我們可以不用自己寫這種迴圈，而是呼叫copy輕鬆地印出vec中的元素：*/
	//for (string s : v)
	//	*outf++ = s;
	//	//outf = s;//解參考運算子和遞增運算子也可省略（詳頁406）
	cout << endl;//此行是讓Visual Studio在 start without debugging的時候，最末它提供的提示文字可以放在下一行再印出
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
