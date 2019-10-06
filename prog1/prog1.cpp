// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）
#include<forward_list>
#include<list>
#include<vector>
using namespace std;
int main() {
	// silly loop to remove even-valued elements and insert a duplicate of odd-valued 	elements
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	list<int> lsti = { 0,1,2,3,4,5,6,7,8,9 };
	forward_list<int> flsti = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin(); // call begin, not cbegin because we're changing
	auto iterl = lsti.begin();
	auto iterf = flsti.begin();
	auto iterfprev = flsti.before_begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter); // duplicate the current
			iterl = lsti.insert(iterl, *iterl); // duplicate the current
			iterf = flsti.insert_after(iterf, *iterf); // duplicate the current element
			iter += 2; // advance past this element and the one inserted before it
			++iterl; ++iterl;//list不能隨機存取元素，只能迭代巡覽，所以其迭代器沒有整數加減運算
			iterfprev=iterf; ++iterf;//forward_list是沒有--(遞減)運算，不能點頭的，只能advance（向前forward）
		}
		else
		{
			iter = vi.erase(iter); // remove even elements
			iterl = lsti.erase(iterl); // remove even elements			
			iterf = flsti.erase_after(iterfprev); // remove even elements
			// don't advance the iterator; iter denotes the element after the one we erased 
		}
	}
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
