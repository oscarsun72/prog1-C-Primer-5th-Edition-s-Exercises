#ifndef STRBLOB_H
#define STRBLOB_H
#include<string>
#include<memory>
#include<vector>
using namespace std;
class StrBlob
{
public:
  typedef vector<string>::size_type size_type;//以型別別名定義型別成員（type member）
  StrBlob();//預設建構器，只有宣告，沒有定義（實作）
  StrBlob(initializer_list<string> il);//帶了一個initializer_list<string>參數的建構器，也只有宣告，沒有定義（實作）
  size_type size() const { return data->size(); }//常值的const成員函式
  bool empty() const { return data->empty(); }//常值的const成員函式
  // add and remove elements
  void push_back(const string &t) { data -> push_back(t); }
  void pop_back();//pop_back//只有宣告，沒有實作（定義）
  // element access
  string &front();
  string &back();

private:
  shared_ptr<vector<string>> data;
  // throws msg if data[i] isn't valid
  void check(size_type i, const string &msg) const; //常值的const成員函式，只有宣告
};
#endif
