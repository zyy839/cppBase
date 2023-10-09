#include <iostream>
using namespace std;
#include<deque>
// 3.3.5 deque插入和删除
/*
尾部
头部
尾删
头删
插入insert
删除clear

插入和删除需要提供位置迭代器。
*/
//两端操作；
void printDeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it= d.begin();it != d.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;

}
void test01()
{
    deque<int>d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);
    //头插
    d1.push_front(5);
    d1.push_front(1000);
    printDeque(d1);
    //尾删
    d1.pop_back();
    printDeque(d1);
    //头删
    d1.pop_front();
    printDeque(d1);
}

void test02()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(300);
    d1.push_front(300);
    //
    printDeque(d1);
    //insert
    d1.insert(d1.begin(),1000);
    printDeque(d1);
    d1.insert(d1.begin(),2,210000);
    printDeque(d1);

    //按区间插入
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(),d2.begin(),d2.end());//指定位置插入一个区间
    printDeque(d1);
}
void test03()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_back(40);
    //删除
    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);
    printDeque(d1);
    //按照区间方式删除
    d1.erase(d1.begin(),d1.end());
    //清空
    // d1.clear();
    printDeque(d1);
}
int main()
{
    //test01();
    test02();
    test03();
    return 0;
}