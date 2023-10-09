#include <iostream>
using namespace std;
// string 查找和替
/*
int find(const string& str, int pos = ) const;
int find(const char* s, int pos = @) const;
int find(const char* s, int pos, int n) const;
int find(const char c, int pos = @) const;
int rfind(const string& str, int pos = npos) const;int rfind(const char* s, int pos = npos) const;
int rfind(const char* s, int pos, int n) const;
int rfind(const char c, int pos = @) const;
string& replace(int pos, int n, const string& str);string& replace(int pos, int n,const char* s);
//查找str第一次出现位置,从pos开始查找
//查找s第一次出现位置,从pos开始查找
//从pos位置查找s的前n个字符第一次位置//查找字符C第一次出现位置
//查找str最后一次位置,从pos开始查找
//查找s最后一次出现位置,从pos开始查找//从pos查找s的前n个字符最后一次位置
//查找字符C最后一次出现位置
//替换从pos开始n个字符为字符串str
//替换从pos开始的n个字符为字符串s
*/
void test01()
{
    //find
    string str1 = "2erwtderetdee";
    int pos = str1.find("de");
    pos = str1.rfind("de");
    cout<<"find位置:"<<pos<<endl;
    if(pos==-1)
    {
        cout<<"没找到"<<endl;
    }
    else{
        cout<<"找到了"<<endl;
    }
    //rfind
    pos = str1.rfind("de");
    cout<<"rfind位置:"<<pos<<endl;

    //rfind和find的区别
    // rfind是从右往左查
}
//替换
void test02()
{
    string str1 = "2erwtderetdee";
    str1.replace(1,3,"111ll"); //从1号位之起3个字符替换为11111
    cout<<"str1 = "<<str1<<endl;

}
int main()
{
    test01();
    test02();
    return 0;
}