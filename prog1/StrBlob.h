#ifndef STRBLOB_H
#define STRBLOB_H
#include<vector>
#include<string>
#include<memory>

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    typedef std::vector<std::string>::iterator iterator;
    StrBlob() :data(new std::vector<std::string>){};
    StrBlob(std::initializer_list<std::string> il);
    inline size_type size() const { return data->size(); }
    inline bool empty() const { return data->empty(); }
    // add and remove elements
    inline void push_back(const std::string& t) {data -> push_back(t);}
    inline void pop_back() { data->pop_back(); }
    // element access
    inline std::string& front() { return data->front(); }
    inline std::string& back() { return data->back(); }
    inline std::string& operator[](size_type i) { return data->at(i); }//自定義StrBlob的下標運算子
    //
    inline iterator begin() { return data->begin(); }
private:
    std::shared_ptr<std::vector<std::string>> data;    
    void check(size_type i, const std::string& msg) const;
};

#endif // !STRBLOB_H
