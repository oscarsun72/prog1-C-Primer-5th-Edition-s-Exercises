#include"StrBlob.h"
#include<string>
#include<vector>
#include<memory>
#include <stdexcept>
using namespace std;
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

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this,this->size());
}
//StrBlobPtr StrBlob::begin() {
//	return StrBlobPtr(*this);
//}
//
//StrBlobPtr StrBlob::end()
//{
//	auto ret = StrBlobPtr(*this, data->size());
//	return ret;
//}
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}


// StrBlobPtr的成員函式check會傳回一個shared_ptr的智慧指標，這個指標指向的是元素型別為string的vector物件2：55：10
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();// 用ret區域變數來記下Weak_ptr這個型別StrBlobPtr資料成員wptr，它叫用StrBlobPtr的成員函式lock回傳的結果，這個結果是一個shared_ptr型別的指標；用這個表達式(運算式express)來以測度wptr所指向的vector物件是否還存在。wptr是由StrBlob資料成員data來初始化的，也就是與shared_ptr型別的data指向的是同一個物件，在此這個物件是vector
	if (!ret) //如果傳回來的指標為null值，便等於「0」，條件式就會成立（在C++中true=1,false=0）
		throw std::runtime_error("unbound StrBlobPtr");//要用「runtime_error」要記得「#include <stdexcept>」。「"unbound StrBlobPtr"」表示調用這個check的StrBlobPtr型別物件（它是一個指標型別）並沒有指向任何物件（在這裡是vector裡的元素）——沒有和任何物件繫結（bind）在一塊；而StrBlob的資料成員、型別為shared_ptr的data，指向的則是那個vector
	if (i >= ret->size()) 
		throw std::out_of_range(msg);
	if(i<0)
		throw std::out_of_range(msg);
	return ret; // 只要通過了以上兩個if條件式的檢驗，就可以放心回傳那個由wptr調用lock成員函式回傳的 shared_ptr,這個shared_ptr和wptr是指向同一個的vector//要用「out_of_range」也要記得「#include <stdexcept>」。「ret」應即「return」的縮寫
}
//原課文（中、英文版如下）
/*// 當企圖存取一個不存在的vector元素時， StrBlobPtr就會丟出一個例外：
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg)
const
{
	auto ret = wptr.lock(); // is the vector still around?
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret; // otherwise, return a shared_ptr to the vector
}*/


std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr]; // (*p) is the vector to which this object points
	/*真正「推進」元素是在這行，不是在incr()，incr()只是「推進」索引值而已。再在此deref()先檢查
	索引值curr有效否，有效才「真的」「推進」（其實是對vector的「下標運算」！）
	故反而是在解參考（即deref()）時才「推進」元素（實即對vector下標爾），而不是在incr()就推進了
	真正有「推進」的，只有索引值，而元素並未被「推進」，只是vector被下標（subscript）而已
	第85集 4:5:00 */
}

// prefix: return a reference to the incremented object
StrBlobPtr& StrBlobPtr::incr()
{
	// if curr already points past the end of the container, can't increment it
	/*若如課本，只寫「=」後面的表達式，那麼編譯器會出現這樣的警告訊息：
	Severity	Code	Description	Project	File	Line	Suppression State
	Warning	C26444	Avoid unnamed objects with custom construction and destruction (es.84).	prog1	V:\PROGRAMMING\C++\OSCARSUN72\PROG1\PROG1\STRBLOB.CPP	85	
	*/
	//auto sp = check(curr, "increment past end of StrBlobPtr");
	shared_ptr<vector<string>> sp = check(curr, "increment past end of StrBlobPtr");
	++curr; // advance the current state
	return *this;
}

StrBlobPtr& StrBlobPtr::decr()
{
	auto p = check(curr-1, "遞減過頭了！");
	--curr;	//遞減索引值
	return *this;
}

bool StrBlobPtr::isEnd()
{
	auto p = wptr.lock();
	if (p)
	{
		if (this->curr == p->size())
			return true;
	}
	return false;
}

