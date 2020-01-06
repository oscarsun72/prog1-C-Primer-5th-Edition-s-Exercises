#ifndef TextQuery_H
#define TextQuery_H
#include<vector>
#include<memory>
#include<fstream>
//#include<map>
//#include<set>
using namespace std;
class TextQuery
{

public:
	TextQuery();
	TextQuery(ifstream & infile);
	~TextQuery();

private:

};

TextQuery::TextQuery()
{
}

TextQuery::~TextQuery()
{
}

#endif // !TextQuery_H
