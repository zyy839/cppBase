#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
//2.5.2 Vector存放自定义数据类型
class Person
{
    public:
    Person(string name,int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
void test01()
{
    vector<Person> v;
    Person p1("aaa",12);
    Person p2("bbb",14);
    Person p3("ccc",14);
    Person p5("fff",35);
    Person p4("hui",28);
    // 像容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    // 遍历容器中的数据
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"name:"<<(*it).m_Name<<" age:"<<(*it).m_Age<<endl;
        // cout<<"name:"<<it->m_Name<<" age:"<<it->m_Age<<endl;
    }
    // 存放自定义数据类型指针
}
void test02()
{
        vector<Person*> v;
        Person p1("aaa",12);
        Person p2("bbb",14);
        Person p3("ccc",14);
        Person p5("fff",35);
        Person p4("hui",28);
        // 像容器中添加数据
        v.push_back(&p1);
        v.push_back(&p2);
        v.push_back(&p3);
        v.push_back(&p4);
        v.push_back(&p5);      
        // 遍历容器
        for(vector<Person*>::iterator it=v.begin(); it!=v.end();it++)
        {
            cout<<"name:"<<(*it)->m_Name<<" age:"<<(*it)->m_Age<<endl;
        }

}
int main()
{
    test01();
    test02();
    return 0;
}