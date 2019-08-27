#pragma once
size_t count_calls(size_t i);
int factoral(int f) 	;
void fact() ;
void absv(int ab);
void SwapTwoInt(int* ip1,int *ip2);//練習6.10
int resetVal(int& r);//練習6.11
void SwapTwoInt(int& ir1, int& ir2);//練習6.12
int returnLarger(int i, int* ip);//練習6.21
void swap_two_pointers(int*& i, int*& j);//練習6.22
void print(const int* cip);//練習6.23
void print(const int* beg, const int* end);//練習6.23//Using the Standard Library Conventions
void print(const int ia[], size_t sz);//練習6.23//Explicitly Passing a Size Parameter
void print_Array_Reference_Parameters(const int (&arr)[2]);//練習6.23
void print_Passing_a_Multidimensional_Array_ref(const int (&arr)[2][2]);//練習6.23
void print_Passing_a_Multidimensional_Array_pointer(const int (*arr)[2], int rowSize);//練習6.23
void print_Passing_a_Multidimensional_Array_pointer_size_t(const int (*arr)[2], size_t rowSize);//練習6.23
//這裡的int 是陣列元素的型別，不是陣列的大小,所以不能是unsigned，而須是元素的型別（在這裡是int）。因為二維陣列可看作是row和column，所以才叫rowSize
//而因為指標沒有指定大小，猶如下式第一維度大小的省略，所以須另外再給個第一維大小的參數
//而因為第一維元素的型別為陣列，所以……（還是懷疑這裡int，應該是size_t 的unsinged比較對，因為要告知大小，才能做迭代（iterate）也。
//果然用size_t也可以，且應該比較對，否則如果是負值，這迭代（iterate）的迴圈怎麼寫才好？
void print_Passing_a_Multidimensional_Array_multiArr(const int arr[][2],int rowSize);//練習6.23

//void print_sum_of_the_elements_in_the_list(initializer_list<int> lst);//練習6.27





