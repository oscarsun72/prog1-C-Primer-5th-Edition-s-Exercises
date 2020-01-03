//#pragma once
#ifndef STRBLOB_H
#define STRBLOB_H
#include<string>
#include<vector>
#include<memory>
using namespace std;
 
//class StrBlobPtr;//可以重複宣告，卻不能重複定義；若無此行，則StrBlob中成員函式用 到StrBlobPtr都會在編譯時期出錯「use of undefined type 'StrBlobPtr'」
class StrBlob
{
	friend class StrBlobPtr;//頁269-270,279-280;不加「class」的就會當作函式編譯
	friend class ConstStrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type; //以型別別名定義型別成員（type member）
	StrBlob();                                             //建構器
	StrBlob(std::initializer_list<std::string> il);        //帶了一個initializer_list<string>參數的建構器
	size_type size() const { return data->size(); }        //常值的const成員函式
	bool empty() const { return data->empty(); }           //常值的const成員函式
	// add and remove elements
	void push_back(const std::string& t) {
		data->push_back(t);
	}
	void pop_back();
	// element access
	std::string& front();
	std::string& back();

	// return StrBlobPtr to the first and one past the last elements
	StrBlobPtr begin();
	StrBlobPtr end();

private:
	std::shared_ptr<std::vector<std::string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const std::string& msg) const;
};

//伙伴類別似乎是要放在同一個標頭檔中！！否則編譯（建置）時會出錯。 https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2027?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(C2027)%26rd%3Dtrue%26f%3D255%26MSPPError%3D-2147217396&view=vs-2019
//伙伴類別（companion class，這裡是companion pointer class）是否就要放在同一個標頭檔中呢？！否則就會出錯
class StrBlobPtr
{
	friend class StrBlob;
public:
	StrBlobPtr() : curr(0) {}//第1個建構器（也是預設建構器（default constructor）——沒有引數）
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}//第2個建構器
	StrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}//第3個建構器，針對常值的StrBlob練習12.22
	std::string& deref() const;
	StrBlobPtr& incr(); // 前缀版本(prefix version)
	StrBlobPtr& decr(); // 前缀版本(prefix version)
	bool isEnd();//用來判斷已到末尾元素
private:
	//如果檢查成功，check會回傳一個shared_ptr指向vector
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	// wptr儲存一個weak_ptr，利用它來作為一個底層vector可能已摧毁的指示
	//（指標；這個智慧指標不是用來管控其所指物的生死，而是用來檢查其所指物件是否還存在）
	// store a weak_ptr, which means the underlying vector might be destroyed
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr; // curr是用來指示vector中目前元素的位置
					  // current position within the array——應是英文版筆誤！

};

//一個專門給常值的StrBlob用的ConstStrBlobPtr類別
class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr()=default;
	ConstStrBlobPtr(const StrBlob& cstrb, size_t i = 0) :wptrC(cstrb.data),curr(i){}
	//~ConstStrBlobPtr();//要自定義解構器（destructor）才需要這個，否則應是會和編譯器預設的解構器相衝突，造成編譯錯誤
	ConstStrBlobPtr incr();
	ConstStrBlobPtr decr();
	string& deref()const;
	bool isEnd()const;
	bool isBegin()const;
private:
	shared_ptr<vector<string>> check(size_t , const string&)const;
	weak_ptr<vector<string>>wptrC;
	size_t curr;
};

//ConstStrBlobPtr::~Con	stStrBlobPtr()
//{
//}
#endif // !STRBLOB_H