#include <iostream>
using namespace std;
// 1.2.5普通函数和函数模板调用规则
// 1.如果函数模板和普通函数都可以实现 优先调用普通函数  注意如果普通函数只有声明没有实现 但是有模板函数的实现 不会直接调用模板会报错
// 2.可以通过空模板参数列表来强制调用函数模板
// 3.函数模板也可以重载
// 4.如果函数模板可以产生更好的匹配，优先调用函数模板

void myPrint(int a,int b)
{
    cout<<"调用普通函数"<<endl;
}
template<class T>
void myPrint(T &a, T &b)
{
    cout<<"d调用模板"<<endl;
}

template<class T>
void myPrint(T &a, T &b,T &c)
{
    cout<<"调用重载函数模板"<<endl;
}

void test01()
{
    int a =10;
    int b =20;
    int c = 100;
    // myPrint(a,b); //第一个规则测试
    myPrint<>(a,b); //第二个规则测试
    myPrint(a,b,c); //第三个规则测试
    char c1 = 'a';
    char c2 = 'c';
    myPrint(c1,c2);//第四个规则测试
}
int main()
{
    test01();
    return 0;
}