#include <iostream>
using namespace std;
// string字符存取
/*
char& operator[](int n);
char& at(int n);
//通过[方式取字符
//通过at方法获取字符

*/
void test01()
{
    string str="hell0";
    cout<<"str = "<<str<<endl;

    //1.通过【】访问单个字符
    for(int i=0;i<str.length();i++)
    {
        cout<<str[i]<<" " ;
    }
    cout<<endl;
    //2.通过at方式访问

    for(int i = 0;i<str.length();i++)
    {
        cout<<str.at(i)<<" ";
    }
    cout<<endl;

    //修改单个字符
    str[0] = 'd';
    cout<<"str = "<<str<<endl;
    str.at(1) = 'd';
    cout<<"str = "<<str<<endl;
}
int main()
{
    test01();
    return 0;
}