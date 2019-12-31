#include"StrBlob.h"
#include<string>
#include<vector>
#include<memory>
#include<exception>
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

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}