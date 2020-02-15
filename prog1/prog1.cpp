// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main() {
	//typedef map<unsigned, unsigned> muu;
	//0 1 2 3 4 5 6 7 8 9
	typedef map<unsigned, string> muu;
	//測試用資料：
	//0 孫守真 1 任真 2 淨空老和尚 3 釋迦牟尼佛 4 維摩詰 5 常律老和尚 6 陳彩瓊居士 7 白雲老禪師 8 慧律法師 9 海賢老和尚 
	muu m;
	//istream_iterator<unsigned>in(cin), end;
	istream_iterator<string>in(cin), end;
	while (in!=end)
	{
		m[(*in++)[0]-48] = *in++;
		//in++;
	}
	cin.clear();
	string s;
	unsigned us(0);
	while (true)
	{
		cout << "輸入一個無號整數，或按q離開" << endl;
		cin >> s;
		if (s=="q")
		{
			break;
		}	
		us = s[0]-48;
		cout <<"下標"<<us<<"得到："<< m[us] << endl;

	}
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
