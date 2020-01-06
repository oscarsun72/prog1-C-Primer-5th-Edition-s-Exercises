#ifndef TextQuery_H
#define TextQuery_H
#include<vector>
#include<memory>
#include<iostream>
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
	shared_ptr<vector<string>>spVs;
};

TextQuery::TextQuery(ifstream & infile)
{
	getline( infile
}

TextQuery::~TextQuery()
{
}

#endif // !TextQuery_H
