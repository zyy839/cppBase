#include <iostream>
using namespace std;
#include <string>
// 1.3类模板
// 1.3.1类模板语法
// 作用: 建立一个通用的类,类中的成员数据类型可以不具体制定,用一个虚拟的 类型来代表.
// 语法相似 在template下一行跟一个类就是类模板
template<class NameType,class AgeType>
class Person
{
    public:
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
    Person<string,int> p1("sunwukomh",999);
    p1.showPerson();
}
int main()
{
    test01();
    return 0;
}