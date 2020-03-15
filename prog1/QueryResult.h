#ifndef QueryResult_H
#define QueryResult_H
#include<vector>
#include<memory>
#include<iostream>
#include<iterator>
#include<set>
#include"TextQuery.h"
using namespace std;
class QueryResult
{
public:
	QueryResult(shared_ptr<pair<string, set<size_t>>>sp_key) :pair_str_set(sp_key) { found = false; }
	QueryResult(shared_ptr<vector<string>>, shared_ptr<pair<string, set<size_t>>>);
	~QueryResult();
	void print();
	set<size_t>::iterator begin();
	set<size_t>::iterator end();
	const shared_ptr<vector<string>>&get_file()const;

private:
	shared_ptr<vector<string>>vs;
	shared_ptr<pair<string, set<size_t>>>pair_str_set;
	bool found;
};

QueryResult::QueryResult(shared_ptr<vector<string>> sp_vec_str, shared_ptr<pair<string, set<size_t>>> sp_pair_str_set)
{
	vs = sp_vec_str;//這樣才是由智慧指標（smart pointer）來管理，而不是
	//vs=*sp_vec_str ←原來寫這樣，就是解參考智慧指標後再把解參考的結果容器，指定（即複製一份）
	//給「vs」這個資料成員；這樣就不合資源共享（共用資源）的原則，反而成複製一份了。第98集2：40：00
	pair_str_set = sp_pair_str_set;
	found = true;
}

QueryResult::~QueryResult()
{
}

inline void QueryResult::print()
{
	ostream_iterator<string>o(cout);
	ostream_iterator<size_t>o_size_t(cout);
	*o++ = pair_str_set->first;
	*o++ = " occurs ";
	if (!found)
		*o++ = "0 time";
	else//如果有找到
	{
		*o_size_t++ = pair_str_set->second.size();
		*o++ = (pair_str_set->second.size() > 1) ? " times" : " time";
		cout << endl;
		for (const size_t i : pair_str_set->second)
		{
			*o++ = "\t(line ";
			*o_size_t++ = i;
			*o++ = ")";
			*o++ = (*vs)[i - 1];
			cout << endl;
		}
	}
	cout << endl;
}

inline set<size_t>::iterator QueryResult::begin(){
	
	return pair_str_set->second.begin();
}

inline set<size_t>::iterator QueryResult::end()
{
	return pair_str_set->second.end();
}

inline const shared_ptr<vector<string>>& QueryResult::get_file()const
{
	return vs;
}

#endif // !QueryResult_H