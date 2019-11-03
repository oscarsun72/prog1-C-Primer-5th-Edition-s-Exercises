// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<fstream>
#include<iterator>
#include<unordered_map>//唯3不同，須引用而已
using namespace std;
int main() {
	unordered_map<string, string>mReplace;//唯3不同
	ifstream ifs("V:\\Programming\\C++\\OCRtxtCorrect1.txt");
	ifstream ifsInput("V:\\Programming\\C++\\input1.txt");
	istream_iterator<string>in(ifs), end;
	string key, value;
	while (in != end) {
		key = *in; value = *++in;
		//mReplace.insert(make_pair(key, value)); ++in;
		mReplace[key]= value; ++in;
		/*下標（subscript）者，會改動已有key的value值，
		而插入insert()者不會（即若鍵值已存在，則不會再插入!） 
		第76集 41:00 46:20 https://youtu.be/uv7w5Vd1yDg */
	}
	istream_iterator<string>input(ifsInput), e;
	unordered_map<string, string>::const_iterator mIt;//唯3不同
	string ocr;
	while (input != e)
	{
		ocr = *input;
		mIt = mReplace.find(ocr);
		if (mIt != mReplace.cend())
			cout << mIt->second << endl;
		else
			cout << ocr << endl;
		++input;
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
