// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<numeric>
#include "Sales_item.h"
#include <functional>
using namespace std::placeholders;
using namespace std;
inline bool compareIsbn1(const Sales_item& s1, const Sales_item& s2) {
	return s1.isbn() < s2.isbn();
}
int main()
{
	istream_iterator<Sales_item>i(cin), end;
	ostream_iterator<Sales_item>o(cout,"\n");
	vector<Sales_item>v(i, end);	
	//若要檢查沒有輸入或輸入錯誤，可在此加判斷
	if (v.empty()) {//沒有輸入！警示使用者
			cerr << "No data?!" << std::endl;
		return -1; //指示失敗
	}	
	vector<Sales_item>vUniqu;
	sort(v.begin(), v.end(), compareIsbn1);
	//unique_copy(v.begin(), v.end(), inserter(vUniqu,vUniqu.begin()));
	//演算法要增減容器大小（元素個數）一定要請「介入者（插入者）迭代器」「代理」！
	//因為 Sales_item定義要資料成員（data　member）都相同才算重複，所以不能用它內建的==
	vector<Sales_item>::const_iterator f,fnext=v.cbegin();
	//for (Sales_item s : vUniqu) {
	//	f = find(fnext, v.cend(), s);
	//	while (find(++f, v.cend(), s) != v.cend()) {//找到相同的Sales_item		
	//	}
	//	*o++=accumulate(fnext, f, Sales_item());
	//	fnext = f;
	//}
	//
	//所以只能逐一其比對.isbn()==.isbn()	
	while (fnext!=v.cend())
	{
		f = find_if_not(fnext, v.cend(),bind(compareIsbn,_1, *fnext));//找到ISBN不同的另一本書在容器中的位置
		//auto a= accumulate(fnext, f, Sales_item());
		* o++ = accumulate(fnext, f, Sales_item(fnext->isbn()));
						//用 Sales_item 帶了一個ISBN參數的建構器來建構accumulate的基點
		fnext = f;
	}
	//---------		----------------------------------
	//以下是本書原型（頁24）
	//Sales_item total; //存放下一筆交易記綠資料的變數
	////讀取第一筆交易記錄，並確保有資料可以處理
	//if (std::cin >> total) {
	//	v.push_back
	//	Sales_item trans; 用來存放運行總和的變數//孫守真按：原書註解錯置，中文版亦未訂正：此當為total的註解，反之亦然。已在線上勘誤，尚未見刊出。頁255在另做Sales_data時已其訂正，可參證
	//	//讀取並處理剩餘的交易記錄
	//	while (std::cin >> trans) {
	//		//如果我們仍然是在處理同一本書
	//		if (total.isbn() == trans.isbn())
	//			total += trans; // 更新累計的 total
	//		else {
	//			//印出前一本書的結果
	//			std::cout << total << std::endl;
	//			total = trans; // total現在指向下一本書
	//		}
	//	}
	//	std::cout << total << std::endl; // 印出最後一筆交易記錄
	//}
	//else {
	//	//沒有輸入！警示使用者
	//	std::cerr << "No data?!" << std::endl;
	//	return -1; //指示失敗
	//}
	//return 0;
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
