// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
#include<vector>
using namespace std;

int main() {
	vector<int> veci;
	//Every container type defines a default constructor (§ 7.1.4, p. 263). 
	//With the 	exception of array, the default constructor creates an empty container of the	specified type.
	/*Again excepting array, the other constructors take arguments that
		specify the size of the container and initial values for the elements.*/
	vector<int>veci1(3,2);
	vector<int>veci2(3);
	/*There are two ways to create a new container as a copy of another one: 
	We can directly copy the container:*/
	vector<int>veci3= veci1;//容器拷貝時，容器型別與元素型別必須一致
	vector<int>veci31(veci1);//the constructor that takes a container to copy
	// or (excepting array) we can copy a range of elements denoted by a pair of iterators.:
	vector<int>veci4(veci2.begin(), veci2.end());
	vector<int>veci5 = {1,1,1};
	vector<int>veci6(4,4);
	veci6 = { 1,1,1 };//size會改變成串列的，而不是不足的用值初始化！veci6.size=3,veci6.capacity()=4;
	//好像只有array因為是固定大小，串列初始化（list initialization）不夠的剩下才會用值初始化
}



//int main(int argc, const char** argv)
//{
//	print_sum_of_the_elements_in_the_list({ 11,2,3 });
//	return 0;
//}


			//printf("%i\n", i);
			//std::cout << "Hello World!\n";



// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
