#include <iostream>
using namespace std;
//1.2.6模板的局限性
// 
// 模板并不是万能的 有些特定数据类型需要集体化方式做特殊实现.自定义数据类型判断相等时。。。

// 利用具体化的模板 可以解决自定义类型的通用化
// 学习模板并不是为了写模板 是为了在STL中运用系统提供的模板.
class Person
{
    public:
    Person(string name,int age)
    {
        this->m_name = name;
        this->m_Age = age;
    }
    string m_name;
    int m_Age;
};
template<class T>
bool myCompare(T&a,T&b)
{
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// 利用具体化的person的版本来实现代码 具体化会优先调用
template<> bool myCompare(Person &p1,Person &p2)
{
    if(p1.m_name == p2.m_name && p1.m_Age == p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test01()
{
    int a = 10;
    int b = 20;
    bool ret =  myCompare(a,b);
    if(ret)
    {
        cout<<"a==b"<<endl;
    }
    else{
        cout<<"a!=b"<<endl;
    }
}

void test02()
{
    Person p1("tom",10);
    Person p2("tom",10);
    bool ret = myCompare(p1,p2);
    if(ret)
    {
        cout<<"p1==p2"<<endl;
    }
    else{
        cout<<"p1!=p2"<<endl;
    }
}
int main()
{
    test01();
    test02();
    return 0;
}