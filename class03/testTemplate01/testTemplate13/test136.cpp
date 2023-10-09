#include <iostream>
using namespace std;
// 1.3.6类模板成员函数类外实现
// 总结:类模板中成员函数类外实现时,需要加上模板参数列表.
template<class T1,class T2>
class Person
{
    public:
    Person(T1 name, T2 age);
    // {
    //     this->m_Name = name;
    //     this->m_Age = age;
    // }
    void showPerson();
    // {
    //     cout<<"姓名:"<<this->m_Name<<" 年龄"<<this->m_Age<<endl;
    // }
    public:
    T1 m_Name;
    T2 m_Age;

};
// 构造函数的类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
        this->m_Name = name;
        this->m_Age = age;
}
template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
    cout<<"姓名:"<<this->m_Name<<" 年龄"<<this->m_Age<<endl;
}
void test01()
{
    Person<string,int>p("tom",19);
    p.showPerson();
}
int main()
{
    test01();
    return 0;
}