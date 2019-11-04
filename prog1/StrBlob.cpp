#include "StrBlob.h"
#include<memory>//make_shared 要用
#include <stdexcept>//out_of_range 要用
using namespace std;
//StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob()
{
	data = make_shared<vector<string>>();
}
//StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}//用il來作為make_shared引數，就不是空的vector了
StrBlob::StrBlob(initializer_list<string> il)
{
	data = make_shared<vector<string>>(il);
}

void StrBlob::check(size_type i, const string& msg) const
{
	if (i>=data->size())
	{
		throw out_of_range(msg);//須引用stdexcept標頭 #include <stdexcept>
	}
}

void StrBlob::pop_back()
{
	check(0, "pop_back on an empty StrBlob");
	data->pop_back();
}

string& StrBlob::front()
{
	check(0, "front on an empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back() on an empty StrBlob");
	return data->back();
}
