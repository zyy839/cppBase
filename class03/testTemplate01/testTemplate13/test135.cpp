#include <iostream>
using namespace std;
// 1.3.5类模板与继承
// 当子类继承父类是类模板时,子类在声明的时候,要制定出父类中的T的类型
// 如果不指定,编译器无法给子类分配内存
// 如果想灵活指出父类中的T类型,子类也需要变为类模板

template<class T>
class Base
{
    T m;
};
// class Son: public Base//报错: 缺少 类模板 "Base" 的参数列表C/C++(441) 必须知道T的类型才能继承
// {  
// };
class Son: public Base<int>
{ 
 
};
void test01()
{
    Son s1;
}
// 如果想灵活指定父类中的T类型,子类也需要变类模板
template<class T1, class T2>
class Son2:public Base<T2>
{
    public:
    Son2()
    {
        cout<<"T1的类型"<<typeid(T1).name()<<endl;
        cout<<"T2的类型"<<typeid(T2).name()<<endl;
    }
    T1 obj;
};
void test02()
{

    Son2<int,char>S2;
}

int main()
{
    test01();
    test02();
    return 0;
}