// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<vector>
//#include<memory>
//#include<new>
using namespace std;
vector<int> vi{2,3};//由此測試發現make_shared函式是以傳值的方式來傳遞引數的
shared_ptr<vector<int>> returnDynamicallyAllocatedVec() {
	return make_shared<vector<int>>(vi);//因為make_shared引數是以傳值的方式傳遞，故vi只是拷貝副本給shared_ptr用，對shared_ptr的操作，並不會影響原來的vi
}

void read_give_values_to_the_elements(const shared_ptr<vector<int>>& vp) {
	istream_iterator<int>in(cin), end;
	while (in != end)
	{
		vp->push_back(*in++);
	}
}
void print_the_values_that_were_read(const shared_ptr<vector<int>>& vp) {
	ostream_iterator<int>out(cout, ",");
	for (int i : *vp)
	{
		*out++ = i;
	}
}

int main() {
	shared_ptr<vector<int>> vp = returnDynamicallyAllocatedVec();
	read_give_values_to_the_elements(vp);
	print_the_values_that_were_read(vp);
	cout << vp.use_count() << endl;
	if (vp.unique())
	{
		cout << vp.use_count() << endl;
	}
	//vp = nullptr;
	//cout << vp.use_count() << endl;
	vp.reset();//和vp = nullptr是一樣的
	//A shared_ptr stops owning a resource when it's reassigned or reset. https://docs.microsoft.com/en-us/cpp/standard-library/shared-ptr-class?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(MEMORY%2Fstd%3A%3Ashared_ptr%3A%3Areset);k(std%3A%3Ashared_ptr%3A%3Areset);k(reset);k(DevLang-C%2B%2B);k(TargetOS-Windows)%26rd%3Dtrue%26f%3D255%26MSPPError%3D-2147217396&view=vs-2019
	cout << vp.use_count() << endl;
}


//int main(int argc, const char** argv)
//{
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
