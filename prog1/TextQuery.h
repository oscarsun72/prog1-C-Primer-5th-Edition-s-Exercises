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
class QueryResult; //對於query成員函式的回傳值而言，這個宣告是必須，因為QueryResult就是query函式的回傳型別
class TextQuery//頁487
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> file; //指向要被檢索的檔案資料
    //
    map<string, shared_ptr<set<line_no>>> wm;
};

//讀取要檢索的檔案內容以建構含有其每行內容及箭號的map
TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
    string text;
    while (getline(is, text))
    {                             //一行行處理要檢索的檔案
        file->push_back(text);  //將這行的內容存放到vector裡頭
        int n = file->size() - 1; //當前這行的行號
        istringstream line(text); //讀取此行內的各個詞彙
        string word;
        while (line >> word)
        { //處理這行內的個個字彙
            //如果這個字彙並不在wm這個map裡面，就對wm下標來新增這個字彙進去
            auto& lines = wm[word];            //lines這個變數的型別是shared_ptr
            if (!lines)                        //如果這個shared_ptr是個空值的話，那麼這就是第一次加入這個新字彙到wm中
                lines.reset(new set<line_no>); //若此字彙是第一次加入到wm中就配置一個新的set給wm作「值」用
            lines->insert(n);                  //將此行的行號，在set中記下來
        }
    }
}


class QueryResult//頁489
{
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(std::string s,
        std::shared_ptr<std::set<TextQuery::line_no>> p,
        std::shared_ptr<std::vector<std::string>> f) :
        sought(s), lines(p), file(f) {}

private:
    std::string sought; //這次要找的字
    std::shared_ptr<std::set<TextQuery::line_no>>lines;//要找的字所在的行號
    std::shared_ptr<std::vector<std::string>> file; //要被檢索的檔案內容
};
QueryResult TextQuery::query(const string& sought) const
{
    //如果要找的字沒找到的話，就回傳這個指向空set的shared_ptr
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    //用find來找而不是用下標運算，以避免動到wm中的元素
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    //沒有找到的話，就回傳這個QueryResult
    else
        return QueryResult(sought, loc->second, file);
}


#endif // !TextQuery_H