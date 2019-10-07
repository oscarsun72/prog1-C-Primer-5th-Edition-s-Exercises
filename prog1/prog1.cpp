// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
string replaceExercise9_44(string s, string oldVal, string newVal) {
	string::size_type iter (0);
	string::size_type iterOld (0);
	string::size_type sB;// (0);
	while (iter != s.size())
	{
		if (s[iter] == oldVal[iterOld]) {
			sB = iter;
			++iter;
			++iterOld;
			while (iterOld != oldVal.size() && iter != s.size())
			{
				if (s[iter] != oldVal[iterOld]) break;
				++iter;
				++iterOld;
			}
			if (iterOld == oldVal.size())//表示找到
			{//index沒有迭代器（iterator）在編輯元素後失效的問題：
				s.replace(sB, oldVal.size(), newVal);
			}
			iterOld = 0;
		}
		++iter;
	}
	return s;
}

int main() {
	//const string s = "I decided the thru only way to make it thru the tournament and all the highs and lows was to make him a warrior.";
	//string sNew = replaceExercise9_44(s, "thru", "through");
	const string s = "His performance was remarkable, tho , given that tho he was playing through the pain barrier.";
	string sNew = replaceExercise9_44(s, "tho", "though");
	if (s != sNew)
		cout << sNew << endl;
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
