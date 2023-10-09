#include <iostream>
using namespace std;
#include<vector>
// vector容器容量和大小操作
/*

*/

void printVector(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}
void test01()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //判断容器是否为kong
    if(v1.empty())//为真 是空
    {
        cout<<"v1为空"<<endl;
    }
    else
    {
        cout<<"v1不为空"<<endl;
        cout<<"v1的容量为:"<<v1.capacity()<<endl;
        cout<<"v1的大小"<<v1.size()<<endl;

    }
    //重新制定大小
    v1.resize(15);  //默认用0填充
    printVector(v1);

    v1.resize(15,100);  //指定填充值    
    printVector(v1);

    v1.resize(5);
    printVector(v1); //短：超出部分删除
}
int main()
{
    test01();
    return 0;
}