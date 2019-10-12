// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<vector>
#include<string>
#include <iostream>
#include <algorithm>
using namespace std;


string make_plural(size_t count, string word ,string s) {
	return count > 1 ? word + s : word;
}
void biggies(vector<string>& words,
	vector<string>::size_type sz) {
	//elimDups(words); // put words in alphabetical order and remove duplicates
	// sort words by size, but maintain alphabetical order for words of the same size
	stable_sort(words.begin(), words.end(),//sort 預設必是由小到大排序…
		[](const string& a, const string& b)
		{ return a.size() < b.size(); });//…所以須配合著<小於運算子來用！也就是說sort是藉由「<」小於運算子比較的結果來決定由小到大排序的順序的
//要明白這些predicate(p.386)是怎麼作用的，才能真正弄懂
// get an iterator to the first element whose size() is >= sz
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string& a)
		{ return a.size() >= sz; });//可見find_if是用「true」來判斷predicate。且只找第一個符合條件（predicate為true）的
// compute the number of elements with size >= sz
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	// print words of the given size or longer, each one followed by a space
	for_each(wc, words.end(),
		[](const string& s) {cout << s << " "; });
	cout << endl;
}

int main() {
	vector<string>vec;
	string w;
	while (cin>>w)
	{
		vec.push_back(w);
	}
	biggies(vec, 4);
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
