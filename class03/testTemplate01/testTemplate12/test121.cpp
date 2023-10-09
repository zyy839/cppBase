#include <iostream>
using namespace std;
// 1.2函数模板
// 函数模板语法
// 函数米板作用：建立一个通用函数，其函数返回类型和形参类型可以不具体指定 用一个虚拟的类型来代表。
// 语法：template<typename T>     换行 函数声明和定义
// template --声明创建模板  typename--表面器后面的符号是一种数据类型 可以用class代替  T--通用数据类型 ，名称可替换，通常为大写字母。

void swapInt(int &a,int &b)
{
    int temp = a;
    a =b;
    b = temp;
}
void swapDouble(double &a,double &b)
{
    double temp = a;
    a = b;
    b = temp;
}
// 函数模板
template<typename T>//声明一个模板 告诉编译器 后面代码中紧跟的T不要报错，T是一个通用数据类型。
void mySwap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    // swapInt(a,b);
    // 函数模板有两种方式使用
    // 1.自动类型推导
    // mySwap(a,b);
    // 2.显示指定类型
    mySwap<int>(a,b);

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    // double c = 1.1;
    // double d = 2.2;
    // swapDouble(c,d);
    // cout<<"c = "<<c<<endl;
    // cout<<"d = "<<d<<endl;
}


int main()
{
    test01();
    return 0;
}