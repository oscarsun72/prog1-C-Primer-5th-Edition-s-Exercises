#ifndef QueryResult_H
#define QueryResult_H
#include<vector>
#include<memory>
#include<iostream>
#include<iterator>
#include"TextQuery.h"
using namespace std;
class QueryResult
{
public:
	QueryResult() { found = false; }
	QueryResult(shared_ptr<vector<string>>,shared_ptr<pair<string,set<size_t>>>);
	~QueryResult();
	void print();
	bool found;

private:
	vector<string>vs;
	pair<string, set<size_t>>pair_str_set;
};

QueryResult::QueryResult(shared_ptr<vector<string>> sp_vec_str,shared_ptr<pair<string,set<size_t>>> sp_pair_str_set)
{
	vs = *sp_vec_str;
	pair_str_set = *sp_pair_str_set;
	found = true;
}

QueryResult::~QueryResult()
{
}

inline void QueryResult::print()
{
	ostream_iterator<string>o(cout);
	ostream_iterator<size_t>o_size_t(cout);
	*o++ = pair_str_set.first;
	*o++ = " occurs ";
	if (!found)
		*o++ = "0 tiem";
	else//如果有找到
	{
		*o_size_t++ = pair_str_set.second.size();
		*o++ = (pair_str_set.second.size()>1)?" times":" time";
		cout << endl;
		for (const size_t i:pair_str_set.second)
		{
			*o++ = "\t(line ";
			*o_size_t++ = i;
			*o++ = ")";
			*o++ = vs[i - 1]; 
			cout<< endl;
		}

	}
}

#endif // !QueryResult_H
