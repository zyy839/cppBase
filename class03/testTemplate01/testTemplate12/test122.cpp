#include <iostream>
using namespace std;
// 1.2.2模板函数的注意事项 
template<class T> //typename可以替换成class
void mySwap(T&a,T&b)
{
    T temp = a;
    a = b;
    b = temp;

}
// 两点：1.自动类型推导：必须推导出一致的数据类型才能使用


void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    
    mySwap(a,b);
    // mySwap(a,c);报错 自己推导出有问题 推导不出一致的T类型。

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
   
}
// 第二点：2.模板必须能确定出T的数据类型，才能使用
template<class T>
void func()
{
    cout<<"func的调用"<<endl;
}
void test02()
{
    // func(); 没有与参数列表匹配的 函数模板 "func" 实例
    func<int>();
}
int main()
{
    test01();
    test02();
    return 0;
}