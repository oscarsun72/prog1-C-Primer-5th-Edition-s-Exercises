// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<vector>
using namespace std;
class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type; //以型別別名定義型別成員（type member）
	StrBlob();                                             //建構器
	StrBlob(std::initializer_list<std::string> il);        //帶了一個initializer_list<string>參數的建構器
	size_type size() const { return data->size(); }        //常值的const成員函式
	bool empty() const { return data->empty(); }           //常值的const成員函式
	// add and remove elements
	void push_back(const std::string& t) {
		data -> push_back(t);
	}
	void pop_back();
	// element access
	std::string& front();
	std::string& back();
private:
	std::shared_ptr<std::vector<std::string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const std::string& msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {} //用il來作為make_shared引數，就不是空的vector了

void StrBlob::check(size_type i, const string& msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()
{
	// if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

// StrBlobPtr會在試著存取一個不存在的元素時擲出一個例外
class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr(); // 前缀版本(prefix version)
private:
	//如果檢查成功，check會回傳一個shared_ptr指向vector
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	//儲存一個weak_ptr，這表示底層的vector可能被摧毁了
	// store a weak_ptr, which means the underlying vector might be destroyed
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr; //在陣列中的目前位置// current position within the array
};
int main() {	
	
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
