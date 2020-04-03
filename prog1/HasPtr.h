#ifndef HASPTR_H
#define HASPTR_H
#include<string>
class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
    //每個HasPtr物件都有一個ps指標指向的那個string的副本
    HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) {}
    HasPtr& operator=(HasPtr);
    ~HasPtr() { delete ps; }
    
private:
    std::string* ps;
    int i;
};
inline void swap(HasPtr&lhs,HasPtr&rhs){//頁517
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
inline HasPtr& HasPtr::operator=(HasPtr rhs) {//頁518
    swap(rhs, *this);
    return *this;
}



#endif // !HASPTR_H
