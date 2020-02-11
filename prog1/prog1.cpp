// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<fstream>
#include<iterator>
#include<map>
#include<string>
using namespace std;
map<string, string>buildMap(ifstream& map_file)
{
    map<string, string> trans_map; //用來儲存文字轉換規則的map容器
    string key;                    //表示文字轉換規則中待轉之字
    string value;                  //用來取代轉換字的片語
    //將ifstream中的第1個字儲存到key中作為map中的鍵值，而其同一行中其餘的部分，則存放在value，作為map元素的「值」，是要取代原文字的片語
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)                 //檢查若有轉換規則存在；因為包含了前綴的半形空格，所以size最少是1，而不是0。
            trans_map[key] = value.substr(1); //略去原字串stringvalue前綴的半形空格
            //trans_map.insert({key, value.substr(1) }); //insert若已有鍵值不會覆蓋前面的規則，而下標運算則會。
        else
            //果然是觸發了此行：
            throw runtime_error("no rule for " + key);
            //break;
    return trans_map;
}

int main() {
    ifstream ifs("G:\\我的雲端硬碟\\programming程式設計開發\\C++_Primer_5th_e_exercise_test_files\\exercise11_34transformRule.txt");
    map<string,string> m= buildMap(ifs);
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
