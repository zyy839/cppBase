#include <iostream>
using namespace std;
#include<deque>
#include<algorithm> //标准算法头文件
// deque 容器排序
/*
deque容器 
sort


*/
void printDeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it = d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";

    }    cout<<endl;

}
void test01()
{
    deque<int>d;
    d.push_back(20);
    d.push_back(30);
    d.push_back(50);
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    //排序 默认升序
    // 对于支持随访问的的迭代器的容器，都可以利用sort算法直接对其进行排序
    // vector容器也可以利用sort排序。
    printDeque(d);
    sort(d.begin(),d.end());  //数据stl标准算法。
    cout<<"排序后"<<endl;
    printDeque(d);
}
int main()
{
    test01();
    return 0;
}