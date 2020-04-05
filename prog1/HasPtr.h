#ifndef HASPTR_H
#define HASPTR_H
#include<string>
class HasPtr//類指標行為的類別
{
	friend void swap(HasPtr&,HasPtr&);
public:
	//預設建構器
	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0), user_cnt(new size_t(1)) {  }
	//拷貝建構器
	HasPtr(const HasPtr& hp) :ps(hp.ps), i(0), user_cnt(hp.user_cnt) { ++* user_cnt; }
	//拷貝指定運算子
	HasPtr& operator=(const HasPtr& hp) {
		++* hp.user_cnt;
		//和解構器~HasPtr()做的是同一件事：
		//if (-- * user_cnt == 0)
		//{
		//	delete ps;
		//	delete user_cnt;
		//}//以上和解構器~HasPtr()做的是同一件事，只是解構器似乎不能被呼叫，故可另寫一個介面或成員函式來用
		destroy();
		if (*user_cnt != 0&&ps!=hp.ps) {//不是自拷貝/指定時才執行
			ps = hp.ps;
			i = hp.i;
			user_cnt = hp.user_cnt;
		}
		return *this;
	}
	//HasPtr& operator=(HasPtr);
	////swap
	~HasPtr() {
		//if (-- * user_cnt == 0) {
		//	delete ps;
		//	delete user_cnt;
		//}
		destroy();
	}
private:
	std::string* ps;
	int i;
	size_t* user_cnt;
	void destroy() {
		if (-- * user_cnt == 0) {
			delete ps;
			delete user_cnt;
		}
	}
};

void swap(HasPtr& lhs,HasPtr& rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	swap(lhs.user_cnt, rhs.user_cnt);

}
//
////copy and swap（拷貝對調）
//HasPtr& HasPtr::operator=(HasPtr hp) {
//	swap(*this, hp);	
//	return *this;	
//}
#endif // !HASPTR_H
