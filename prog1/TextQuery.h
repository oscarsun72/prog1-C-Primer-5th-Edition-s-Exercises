#ifndef TextQuery_H
#define TextQuery_H
#include<vector>
#include<memory>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>//要用getline函式，要引入這一行
#include<map>
#include<set>
using namespace std;
class TextQuery
{
	friend class QueryResult;
	typedef pair<map<string, size_t>::const_iterator, map<string, size_t>::const_iterator> pair_iterator_map;
public:
	TextQuery();
	TextQuery(ifstream & infile);
	~TextQuery();
	pair_iterator_map query(const string &);
private:
	shared_ptr<vector<string>>spVs;
	multimap<string,size_t>word_lineNum;//一個字詞key(string)會有好幾行與之對應，故用multimap
	set<size_t>lineNum;
};

TextQuery::TextQuery(ifstream & infile)
{
	string lStr,word;	
	size_t line_Num;
	while (infile&&infile.eof())
	{
		getline(infile, lStr); 
		spVs->push_back(lStr);//one line of text in an element
		++line_Num;
		lineNum.insert(line_Num);
		istringstream isstr(lStr);		
		while (isstr>>word)
		{
			word_lineNum.insert(make_pair( word, line_Num));
		}
	}
	
}

TextQuery::~TextQuery()
{
}

inline  TextQuery::pair_iterator_map TextQuery::query(const string& wordForQuery)
{
	//4：18：23//4:31:30回傳的應該是檢索結果，用allocator物件記錄在動態記憶體（dynamic memory），再與QueryResult物件共用此資料
	pair_iterator_map wl = word_lineNum.equal_range(wordForQuery);

}

#endif // !TextQuery_H
