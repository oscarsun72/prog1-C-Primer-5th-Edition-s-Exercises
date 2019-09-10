#include "Screen.h"

string Screen::get(pos startPos, pos length)const //不能用inline 
{
	pos x = startPos + length;
	string s;
	if (x < contents.size())
	{
		for (size_t i = startPos; i < x; i++)
		{
			s.push_back(contents[x]);
		}
		return s;
	}
	return "";
}
inline
void Screen::some_member() const
{
	++access_ctr; // keep a count of the calls to any member function
// whatever other work this member needs to do
}

//inline 
Screen& Screen::set(char c)
{
	if (curser < contents.size())
	{
		contents[curser] = c; return *this;// TODO: insert return statement here
	}
	else
	{
		cout << "curser位置有誤！" << endl;
		return *this;
	}
}

inline //set move 3式中只有此式可以inline 
Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * w + col] = ch; return *this; // TODO: insert return statement here
}
//inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * w;
	curser = row + c; return *this;
}
