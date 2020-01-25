#ifndef QueryResult_H
#define QueryResult_H
#include<vector>
#include<memory>
#include"TextQuery.h"
using namespace std;
class QueryResult
{
public:
	QueryResult(shared_ptr<vector<string>>);
	~QueryResult();

private:

};

QueryResult::QueryResult(shared_ptr<vector<string>> sp)
{

}

QueryResult::~QueryResult()
{
}
#endif // !QueryResult_H
