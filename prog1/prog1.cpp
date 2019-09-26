// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct PersonInfo {
	string name;
	vector<string>phones;
};
int main() {
	string line, word; // will hold a line and word from input, respectively
	vector<PersonInfo> people; // will hold all the records from the input
	// read the input a line at a time until cin hits end-of-file (or another error)
	istringstream record; // bind record to the line we just read
	ifstream ifstrm("V:\\Programming\\C++\\new 2.h");//檔案編碼目前只支援 ANSI和Big5，還不支援UTF-8
	while (getline(ifstrm, line)) {
		PersonInfo info; // create an object to hold this record's data
		record.str(line);
		if (record.eof())//關鍵在這！因為record移位（shift）後在處理下一筆記錄（下一行）前未歸位
			record.clear();
		record >> info.name; // read the name
		while (record >> word) // read the phone numbers
			info.phones.push_back(word); // and store them
		people.push_back(info); // append this record to people
	}
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
