#include <iostream>
using namespace std;
// 1.2.4普通函数与函数模板的区别
// 1.普通函数调用可以发生隐式类型转换
// 2.函数模板 用自动类型推导 不可以发生隐式类型转换
// 3.函数模板用显示指定类型，可以发生隐式类型转换

// 普通函数
int myAdd01(int a,int b){
    return a+b;
}
template<class T>
T myAdd02(T &a,T &b)
{
    return a+b;
}
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c'; //a-97 c-99
    cout<<myAdd01(a,c)<<endl;  //自动将c转换为acsii
    cout<<myAdd02(a,b)<<endl;
    // 自动类型推导
    // cout<<myAdd02(a,c)<<endl; 报错 没有与参数列表匹配的 函数模板 "myAdd02" 实例
    // 显示指定类型

    cout << myAdd02<int>(a,b) << endl;
    // cout << myAdd02<int>(a,c) << endl;   ???按道理 这应该不报错 ？？？？
}

int main()
{
    test01();
    return 0;
}