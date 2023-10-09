#include <iostream>
using namespace std;
#include <string>
// 1.3.2类模板与函数模板的区别
// 1.类模板没有自动类型推导的使用方式
// 2.类模板在模板参数列中中可以有默认参数(只有类模板可以 函数模板不可以)
template<class NameType,class AgeType = int>
class Person
{
    public :
    Person(NameType name,AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout<<"name:"<<this->m_Name<<" age:"<<this->m_Age<<endl;
    }
    NameType m_Name;
    AgeType m_Age;
};
void test01()
{
    // 1.类模板没有自动类型推导的使用方式
    Person<string, int> p("孙悟空",999);//正确 只能用显示指定类型
    p.showPerson();
}
//  2.类模板在模板参数列中中可以有默认参数
void test02()
{
    Person<string> p("猪八戒",1999);
    p.showPerson();
}
int main()
{
    test01();
    test02();
    return 0;
}