#ifndef EXERCISE9_51_H
#define EXERCISE9_51_H
#include<string>
#include<vector>
using namespace std;
class EXERCISE9_51 {
	unsigned y = 0;
	unsigned m = 0;
	unsigned d = 0;
public:
	EXERCISE9_51() : y(2019), m(1), d(1) {}
	EXERCISE9_51(string date) {
		//January 1, 1900
		//Jan 1, 1900 
		//1/1/1900
		//找月份
		vector<string>mon{ "January","February","March","April","May","June","July","August","September","October","November","December" };
		string::size_type i = 0;
		for (string s : mon) {
			if (date.find(s) != string::npos) {
				m = i + 1;
				break;
			}
			++i;
		}
		//找不到 m==0
		//找日期
		string::size_type half_space = date.find(" ");
		string::size_type comma = date.find(",");
		if (half_space != string::npos)
		{
			if (comma != string::npos)
			{
				d = stoul(date.substr(half_space + 1, comma - half_space));
			}
		}
		//找年份
		if (comma != string::npos)
		{
			if (comma + 1 < date.size())
				y = stoul(date.substr(comma + 1));
		}
		if (m == 0) {//還沒找到月份的話
			mon={ "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
			i = 0;
			for (string s : mon) {
				if (date.find(s) != string::npos) {
					m = i + 1;
					break;
				}
				++i;
			}
		}
		string::size_type slash = date.find("/");
		if (m == 0) {//還沒找到月份的話
			if (slash != string::npos) {
				m = stoul(date.substr(0, slash));
			}
		}
		string::size_type slash1 = date.find("/", slash + 1);
		if (d == 0) {
			if (slash!=string::npos)
			{
				d = stoul(date.substr(slash + 1, slash1- slash));
			}
		}
		if (y == 0) {
			if (slash1!=string::npos)
			{
				y = stoul(date.substr(slash1 + 1));
			}
		}
	}
};
#endif