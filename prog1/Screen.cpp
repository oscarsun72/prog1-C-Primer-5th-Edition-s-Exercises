#include "Screen.h"

string Screen::get(pos startPos, pos length)const //不能用inline 
{
	pos x = startPos + length;
	string s;
	if (x<contents.size())
	{
		for (size_t i = startPos; i < x; i++)
		{	
			s.push_back( contents[x]);
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