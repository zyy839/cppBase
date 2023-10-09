#include <iostream>
using namespace std;
// #include"person.h"  类模板中的成员函数一开始不创建所以找不到
// #include"person.cpp" //第一种解决方式:直接包含源文件
// 第二种解决方式(常用):将.h和.cpp的内容写在一起,将后缀改成.hpp文件.
// 总结:建议使用第二种方法.
#include"person.hpp"



// 1.3.7类模板的分文件编写
// 学习目标:掌握类模板成员函数分文件编写产生的问题及解决方式
// 问题:类模板中成员函数创建时机是在调用阶段,导致分文件编写时链接不到
// 解决:解决方式1:直接包含.cpp源文件
// 解决方式2:将声明和实现写在同一文件中,并更改后缀为.hpp,hpp是约定名称,并不是强制
// template<class T1,class T2>
// class Person
// {
//     public:
//     Person(T1 name,T2 age);
//     void showPerson();
//     public:
//     T1 m_Name;
//     T2 m_Age;
// };
// template<class T1,class T2>
// Person<T1,T2>::Person(T1 name,T2 age)
// {
//     this->m_Name= name;
//     this->m_Age = age;
// }
// template<class T1,class T2>
// void Person<T1,T2>::showPerson()
// {
//     cout<<"姓名:"<<this->m_Name<<" age:"<<this->m_Age<<endl;
// }
void test01(){
    Person<string, int> p("小妹",79);
    p.showPerson();
}
int main()
{
    test01();
    return 0;
}