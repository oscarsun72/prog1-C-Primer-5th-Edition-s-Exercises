// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<vector>
//#include<utility>//pair雖定義在此標頭中，但卻不必include就能用，如copy演算法等亦然
using namespace std;
pair<string, int>return_pair(vector<pair<string, int>>::const_iterator iter) {
	return {iter->first,iter->second};
}
int main() {
	vector<pair<string,int>>v;
	vector<pair<string,int>>v1;
	vector<pair<string,int>>v2;
	vector<pair<string,int>>v3;
	//istream_iterator<string>in(cin), end;
	//while (in!=end)	{		
	string w;int i;
	vector<pair<string, int>>::const_iterator v1iter;
	size_t vNo = 0;
	while(cin>>w){
		if (cin >> i) {
			pair<string, int>pr(w, i);//v建構器初始化
			v.push_back(pr);
			pair<string, int>prLI = {w, i };//v1串列初始化（list　initialization）
			v1.push_back(prLI);						
			v1iter = v1.cbegin();//因為插入元素後原迭代器會失效，所以每次都要重取第一元素的迭代器
			v2.push_back(return_pair(v1iter+vNo)); ++vNo;//v2最複雜,由函式傳回值來初始化
			v3.push_back(make_pair(w, i));//v3此式最簡單而直觀！
		}
	}	
	vNo=0;
	vector<pair<string, int>> a[4] = { v,v1,v2,v3 };
	for(vector<pair<string, int>> v:a){
		cout << vNo++ << ":" << endl;
		for (pair<string,int>p:v)
		{
			cout<< p.first; cout << ":"
			<<p.second << endl;
		}
		cout << "---------" << endl;
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
