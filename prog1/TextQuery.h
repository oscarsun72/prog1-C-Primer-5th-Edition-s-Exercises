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
//using namespace std;標頭檔避免用這個
class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&)const;
private:
	std::shared_ptr<std::vector<std::string>>file;
	std::map<std::string, std::shared_ptr<std::set<size_t>>>wm;
};

TextQuery::TextQuery(std::ifstream& is) :file(new std::vector<std::string>)
{
	std::string text;
	while (getline(is, text))//課本頁488沒有「&&!is.eof()」恐怕會出問題
	{
		file->push_back(text);
		int n = file->size() - 1;//頁488
		std::istringstream line(text);
		std::string word;
		while (line >> word)
		{
			auto& lines = wm[word];
			if (!lines)
			{
				lines.reset(new std::set<line_no>);
			}
			lines->insert(n);
		}
	}
}


class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>>p,
		std::shared_ptr<std::vector<std::string>>f)
		:sought(s), lines(p), file(f) {};//英文版這裡和下面對lines的宣告「TextQuery::line_no」又錯了（中文版照錯，頁489） https://play.google.com/books/reader?id=J1HMLyxqJfgC&pg=GBS.PT906.w.2.0.0
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>>lines;
	std::shared_ptr<std::vector<std::string>>file;
};

QueryResult TextQuery::query(const std::string& sought)const
{
	static std::shared_ptr<std::set<TextQuery::line_no >>
		nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
std::ostream& print(std::ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() <<
		((qr.lines->size() > 1) ? " times" : " time") << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}




#endif // !TextQuery_H
