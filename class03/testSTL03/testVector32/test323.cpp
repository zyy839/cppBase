#include <iostream>
using namespace std;
#include<vector>
// vector 赋值操作
/*
三种
等号 
assign
n个elem
*/

void printVestor(vector<int>& v)
{
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    vector<int>v1;
    for(int i =0;i<10;i++)
    {
        v1.push_back(i);
    }
    printVestor(v1);

    //赋值 
    // 等号赋值
    vector<int>v2;
    v2 = v1;
    printVestor(v2);
    // assign 赋值
    vector<int> v3;
    v3.assign(v1.begin(),v1.end());
    printVestor(v3);

    //n个elem；
    vector<int>v4;
    v4.assign(10,100);
    printVestor(v4);
}
int main()
{
    test01();
    return 0;
}