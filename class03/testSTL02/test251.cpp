#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//vector容器存放内置数据类型
void myPrint(int val)
{
    cout<<val<<endl;
}
void test01()
{
    // 1创建了一个vector容器
    vector<int> v;
    // 2向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    // // 3通过迭代器访问容器中的数据
    // vector<int>::iterator itBegin = v.begin();//起始迭代器 指向容器中的第一个元素
    // vector<int>::iterator itEnd = v.end();//结束迭代器 指向最后一个元素的下一个位置
    // //4 第一种遍历方式
    // while(itBegin!=itEnd)
    // {
    //     cout<<*itBegin<<endl;
    //     itBegin++;
    // }

    // //5 第二种遍历方法(
    // for(vector<int>::iterator it = v.begin();it!=v.end();it++)
    // {
    //     cout<<*it<<endl;
    // }

    // 6第三中遍历算法锕  stl提供
    for_each(v.begin(),v.end(),myPrint);//回调技术 一开始不调用 for_each遍历时调用
}
int main()
{
    test01();
    return 0;
}