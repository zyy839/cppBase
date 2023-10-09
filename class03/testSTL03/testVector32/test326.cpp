#include <iostream>
using namespace std;
#include<vector>
// vector数据存取
/*
at(int idx);
operator[];
front();
back();
//返回索引idx所指的数据//返回索引idx所指的数据//返回容器中第一个数据元素//返回容器中最后一个数据元素

总结:
除了用迭代器获取vector容器中元素，[]和at也可以

front返回容器第一个元素
back返回容器最后一个元素
*/
void test01()
{
    vector<int>v1;
    for(int i = 0;i<10;i++)
    {
        v1.push_back(i);
    }
    // 用中括号的方式访问
    for(int i = 0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<"用中括号的方式访问"<<endl;
    // 用at的方式访问
    for(int i = 0;i<v1.size();i++)
    {
        cout<<v1.at(i)<<" ";
    }
    cout<<"用at的方式访问"<<endl;

    // 获取第一个元素
    cout<<"第一个元素"<<v1.front()<<endl;
    //获取最后一个元素
    cout<<"最后一个元素"<<v1.back()<<endl;
}
int main()
{
    test01();
    return 0;
}