#include <iostream>
using namespace std;
// 1.3.8类模板与友元
// 掌握类模板配合友元函数的类内和类外实现
// 全局函数类内实现:直接在类内生命友元即可
// 全局函数类外实现:需要提前让编译器知道全局函数的存在

// 通过全局函数 打印person信息

// 建议类内实现
template<class T1,class T2>
class Person; //person又是个模板 需要再提前声明模板

// 全局函数类外实现  需要让编译器提前知道这个函数的存在 提前知道这个函数就需要声明一下person类
template<class T1,class T2>
void printPerson2(Person<T1,T2> p ) //函数模板实现
{
    cout<<"类外实现:name:"<<p.m_Name<<" age:"<<p.m_Age<<endl;
}

template<class T1,class T2>
class Person
{
    // 全局函数 类内实现
    friend void printPerson(Person<T1,T2> p )
    {
        cout<<"name:"<<p.m_Name<<" age:"<<p.m_Age<<endl;
    }

    //全局函数类外实现  需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1,T2> p );  //普通函数声明
    public:
    Person(T1 name,T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    private:
    T1 m_Name;
    T2 m_Age;
};

// 全局函数在类内的实现

void test01()
{
    Person<string,int> p("tom",20);
    printPerson(p);
}
// 全局函数类外实现
void test02()
{
    Person<string,int>p("hdaiu",12);
    printPerson2(p);
}
int main()
{
    test01();
    test02();
    return 0;
}