// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<map>
using namespace std;
int main() {
	using mss = multimap<string, string>;
	using pmssi = pair<mss::iterator,mss::iterator>;
	mss authors;
	//照作品字母順序插入元素
	istream_iterator<string>in(cin), end;	
	string s;
	while (in != end)
	{
		s = *in++;
		pair<string, string> au_work = make_pair(s, *in++);
		//沒錄到的見臉書直播488集1:48:00前後 https://www.facebook.com/oscarsun72/videos/2553453558099096
		if (authors.size() == 0)
			authors.insert(au_work);
		else
		{
			if (authors.count(au_work.first) == 0)
				authors.insert(au_work);
			else//作品排序
			{
				mss::iterator mp=authors.end();
				for (pmssi pos = authors.equal_range(au_work.first); pos.first != pos.second; pos.first++)
				{
					if (pos.first->second >= au_work.second)//insert都是前位插入，所以既有的作品要大於要插入的，才會插在其前
					{
						mp=authors.insert(pos.first,au_work);//記下有沒有插入成功
						break;
					}
				}
				if (mp == authors.end())
					authors.insert(au_work);//若作品字母順序是現有中最大的，直接插入，就會墊底
			}
		}
	}
	//input string:輸入用測試資料如下：
	//Barth,John Lost　in　the　Funhouse Barth,John Sot-Weed　Factor Y,John Lost　in　the　Funhouse Y,John A　Lost　in　the　Funhouse Sun,Oscar 顧炎武經世思想研究 Sun,Oscar 翁方綱及其文獻學研究
	//Barth,John Sot-Weed　Factor Barth,John Lost　in　the　Funhouse Y,John Lost　in　the　Funhouse Y,John A　Lost　in　the　Funhouse Sun,Oscar 顧炎武經世思想研究 Sun,Oscar 翁方綱及其文獻學研究
	/*authors.insert({ "Barth,John","Sot-Weed Factor" });
	authors.insert({ "Barth,John","Lost in the Funhouse" });
	authors.insert({ "S,John","Lost in the Funhouse" });
	authors.insert({ "S,John","A Lost in the Funhouse" });
	authors.insert({ "Oscar Sun","顧炎武經世思想研究" });
	authors.insert({ "Oscar Sun","翁方綱及其文獻學研究" });*/
	//cout << authors.size() << endl;
	//cout << authors.count("Barth,John") << endl;
	//while (authors.count("Barth,John") > 0)
	//{
	//	authors.erase(authors.find("Barth,John"));
	//}
	//cout << authors.size() << endl;
	ostream_iterator<string>o(cout, ",");
	for (mss::value_type elemt : authors)
	{
		(o++ = elemt.first) = elemt.second; cout << endl;
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
