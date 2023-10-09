#include <iostream>
using namespace std;
//字符串比较
/*
int compare(const char *s) const;
int compare(const string &s) const; //与字符串s比较
//与字符串s比较 

主要用来比较是否相等 
*/
void test01()
{
    string str1 = "hello";
    string str2 = "hello";
    if(str1.compare(str2) == 0)
    {
        cout<<"str1等于str2"<<endl;
    }
    else if(str1.compare(str2)>0)
    {
        cout<<"str1大于str2"<<endl;

    }
    else{
        cout<<"str1小于str2"<<endl;
    }
}
int main()
{
    test01();
    return 0;
}