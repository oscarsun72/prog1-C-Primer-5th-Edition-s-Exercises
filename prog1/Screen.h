#pragma once
#ifndef Screen_H
#define Screen_H
#include<string>
#include<iostream>
using namespace std;
class Screen
{
	public:
		typedef string::size_type pos;
		Screen() = default;
		Screen(pos w,pos h,char c ) :w(w),h(h),contents(h*w,c){}
		//Screen(pos w, pos h, char c) :w(w), h(h), contents{ c }{}//字元作為字串型別的初始器，原來是用{}
		Screen(pos w,pos h,string s ) :w(w),h(h),contents(s){}
		Screen(pos w,pos h,pos ctrBlanks ) :w(w),h(h),contents(ctrBlanks,' '){}

		inline char get() { if(curser<contents.size())  return contents[curser]; }
		string get(pos startposition,pos length) const; //不能用inline 
		void some_member() const;		

		Screen& set(char);//之所以要傳回對Screen的參考，是為了set move display等方法可以連動地用
		Screen& set(pos,pos,char);
		Screen& move(pos,pos);
		Screen& display(ostream& os) { do_display(os); return *this; }
		const Screen& display(ostream& os)const { do_display(os); return *this; }
	private:
		 mutable size_t access_ctr=0; // may change even in a const object
		// other members as before
		 pos curser = 0;
		 pos w = 0, h = 0;
		 string contents;
		void do_display(ostream& os)const { os << contents; }
};

#endif // !Screen_H

