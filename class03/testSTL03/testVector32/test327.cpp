#include <iostream>
using namespace std;
#include<vector>
// 
/*
3.2.7 vector互换容器
功能描述:
实现两个容器内元素进行互换
函数原型:
swap(vec); // 将vec与本身的元素互换
*/
void printVector(vector<int>&v)
{
    for(vector<int>::iterator it = v.begin();it!=v.end();it++)
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

    vector<int>v2;
    for(int i=9;i>0;i--)
    {
        v1.push_back(i);
    }

    printVector(v1);
    printVector(v2);

    cout<<"交换后"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

//2. 实际用途
//收缩内存空间
void test02()
{
    vector<int>v;
    for(int i = 0;i<10000;i++)
    {
        v.push_back(i);
    }
    cout<<"容量"<<v.capacity()<<endl;
    cout<<"大小："<<v.size()<<endl;
    v.resize(3);
    cout<<"容量"<<v.capacity()<<endl;
    cout<<"大小："<<v.size()<<endl;

    //swap收缩
    vector<int>(v).swap(v);
    cout<<"----------收缩操作后"<<endl;
    cout<<"容量"<<v.capacity()<<endl;
    cout<<"大小："<<v.size()<<endl;

}


int main()
{
    //test01();
    test02();
    return 0;
}