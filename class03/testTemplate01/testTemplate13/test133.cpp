#include <iostream>
using namespace std;
// 1.3.3类模板中的成员函数创建时机
// 类模板中的成员函数并不是一开始就创建的,在调用时才会创建
class Person1
{
    public:
    void showPerson1()
    {
        cout<<"person1 show"<<endl;
    }
};
class Person2
{
    public:
    void showPerson2()
    {
        cout<<"person2 show"<<endl;
    }
};

template<class T>
class MyClass
{
    public:
    T obj;
    // 类模板中的成员函数 一开始编译器不会去 调用才会编译
    void fun1()
    {
        obj.showPerson1();
    }
    void fun2()
    {
        obj.showPerson2();
    }

};
void test01()
{
    MyClass<Person1> m;
    m.fun1();
    // m.fun2();  调不到 说明调用时才创建
}
int main()
{
    test01();
    return 0;
}