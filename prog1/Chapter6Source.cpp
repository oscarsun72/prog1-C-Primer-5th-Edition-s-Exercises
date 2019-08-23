#include <iostream>
#include<vector>
#include<string>
#include"prog1.h"
#include "Chapter6.h"
//#include<iterator>
using namespace std;
//using std::cout; using std::cin;using std::endl;

size_t count_calls(size_t i)
{
	static size_t ctr = 0; // value will persist across calls
	ctr = i;
	return ctr;
}
int factoral(int f) {
	int r = 1;
	for (size_t i = 1; i <= f; i++)
	{
		r *= i;
	}

	return r;
}
void fact() {
	int r = 1, f;
	cout << "叫块计―ㄤ顶" << endl;
	cin >> f;
	for (size_t i = 1; i <= f; i++)
	{
		r *= i;
	}
	cout << r << endl;
	return;
}

void absv(int ab)
{
	unsigned r = 1;
	if (ab < 0)
	{
		r = ab * -1;
	}
	else
	{
		r = ab;
	}
	cout << r << endl;
	return;
}

void SwapTwoInt(int* ip1, int* ip2)
{
	int i1 = *ip1;
	*ip1 = *ip2;//硂碞琌C粂ē熬ノ皐场ンよΑ
	*ip2 = i1;
	return;
}

int resetVal(int& r)
{
	r = 0;
	return r;
}


bool is_empty616(string& s) { return s.empty(); }

bool contain_capital(const string& s)//絤策6.17
{
	for (char i : s)
	{
		if (isupper(i))
		{
			return true;
		}
	}
	return false;
}

void beLowercase(string& s) {//絤策6.17//璶э笆ま计ぃノconst把σ
	string::iterator si = s.begin();
	while (si != s.end())
	{
		*si = tolower(*si);
		++si;
	}
}

double calc(double);
int count(const string&, char);
int sum(vector<int>::iterator, vector<int>::iterator,
	int);
vector<int> vec(10);

int returnLarger(int i, int* ip)
{
	if (i >= *ip)
	{
		return i;
	}
	else
		return *ip;
}

void swap_two_pointers(int*& i, int*& j)
{
	int* q = i;
	i = j;
	j = q;
}

void print(const int* cp)
{
	cout << *cp << endl;
}


void print(const int* beg, const int* end)
{
	while (beg != end)
	{
		cout << *beg++ << endl;
	}
}
void print(const int ia[], size_t sz)//Explicitly Passing a Size Parameter
{
	for (size_t i = 0; i < sz; i++)
	{
		cout << ia[i] << endl;
	}
}
void print_Array_Reference_Parameters(const int(&arr)[2])
{
	for (int i : arr)
	{
		cout << i << endl;
	}
}

void print_Passing_a_Multidimensional_Array_ref(const int(&arr)[2][2])
{
	//for (const auto &a:arr)
	for (const auto& a : arr)
	{
		for (auto ae : a)
			cout << ae << endl;
	}
}

void print_Passing_a_Multidimensional_Array_pointer(const int(*arr)[2], int rowSize)
{
	for (size_t i = 0; i < rowSize; i++)
	{
		for (int a : arr[i])
		{
			cout << a << endl;
		}
	}

}
void print_Passing_a_Multidimensional_Array_pointer_size_t(const int(*arr)[2], size_t rowSize)
{
	for (size_t i = 0; i < rowSize; i++)
	{
		for (int a : arr[i])
		{
			cout << a << endl;
		}
	}
}
void print_Passing_a_Multidimensional_Array_multiArr(const int arr[][2], int rowSize)
{
	for (size_t i = 0; i < rowSize; i++)
	{
		for (int a : arr[i])
			cout << a << endl;
	}
}
