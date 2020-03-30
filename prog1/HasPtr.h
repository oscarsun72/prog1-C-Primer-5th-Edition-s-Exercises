#ifndef HASPTR_H
#define HASPTR_H
#include<string>
class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0), user_cnt(new size_t(1)) {  }
	HasPtr(const HasPtr& hp) :ps(hp.ps), i(0), user_cnt(hp.user_cnt) { ++* user_cnt; }
	HasPtr& operator=(const HasPtr& hp) {
		++* hp.user_cnt;
		if (-- * user_cnt == 0)
		{
			delete ps;
			delete user_cnt;
		}
		if (*user_cnt != 0&&ps!=hp.ps) {//不是自拷貝/指定時才執行
			ps = hp.ps;
			i = hp.i;
			user_cnt = hp.user_cnt;
		}
		return *this;
	}
	~HasPtr() {
		if (-- * user_cnt == 0) {
			delete ps;
			delete user_cnt;
		}
	}
private:
	std::string* ps;
	int i;
	size_t* user_cnt;
};
#endif // !HASPTR_H
