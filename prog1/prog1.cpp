// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


//#include"prog1.h"
//#include "Chapter6.h"//標準程式庫才用角括弧
//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
//#include "Sales_item.h"//自訂的標頭檔則用雙引號
//#include<string>
//#include "Person.h"
//#include<vector>
#include <iostream>
#include <fstream>
#include "Sales_data.h"
using namespace std;
void main1(int argc, const char* argv[]) {		
	ifstream ifs(argv[argc-2]);
	ofstream ofs(argv[argc - 1],ofstream::app);//本來就是要清空 file mode = out and trunc
	//如果檔案不存在 ofstream會以提供的檔名直接寫入硬碟
	//如果路徑不正確，則會在工作目錄以下建此新檔
	//因此，下述的 ofs.good()和 if(ofs) 就會永遠是 true=1了,不可能出錯了
	//if (ofs.good())
	//	cout<< ofs.good()<<endl;
	if (ifs&&ofs) {
		Sales_data sd;
		if (read(ifs, sd)) {
			Sales_data sdnext;
			while (read(ifs,sdnext))
			{
				if (sd.isbn()==sdnext.isbn())
				{
					sd.combine(sdnext);
				}
				else
				{
					print(ofs, sd) << endl;;
					sd = sdnext;
				}
			}
			print(ofs, sd)<<"-------"<<endl;
		}
		else {
			cout << "交易記錄讀取失敗" << endl;
		}
	}
	else {
		cout << "檔案讀取失敗" << endl;
	}
}
int main(int argc,  char* argv[]) {
	const char* a[2] = { "V:\\Programming\\C++\\Sales_data_transactions.txt" 
						,"V:\\Programming\\C++\\Sales_data_transactions_output.txt"};
	main1(2,a);	
}

//int main(int argc, const char** argv)
//{
//	print_sum_of_the_elements_in_the_list({ 11,2,3 });
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
