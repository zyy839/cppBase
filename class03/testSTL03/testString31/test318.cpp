#include <iostream>
using namespace std;
// string插入和删除
/*
string& insert(int pos, const char* s);
string& insert(int pos, const string& str);
string& insert(int pos, int n, char c);
string& erase(int pos, int n = npos);
//插入字符串
//插入字符串
//在指定位置插入n个字符C
//删除从Pos开始的n个字符
*/
void test01()
{
    string str = "hello";
    //插入
    str.insert(1,"1111");
    cout<<"str = "<<str<<endl;  //str = h1111ello
    //删除
    str.erase(1,3);//从第一个位置起删三个
    cout<<"str = "<<str<<endl;

}
int main()
{
    test01();
    return 0;
}