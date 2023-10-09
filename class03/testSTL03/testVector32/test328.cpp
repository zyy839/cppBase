#include <iostream>
using namespace std;
#include<vector>
// 
/*
3.2.8 vector预留空间
功能描述:
减少vector在动态扩展容量时的扩展次数
函数原型:
reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/
void test01()
{
    vector<int>v;
    int num = 0;//统计开辟次数
    int *p = NULL;
    v.reserve(100000); //预留空间之后只用开辟以此空间
    for(int i =0;i<100000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])//判断指针是不是还指向原有空间
        {
            p = &v[0]; //没有指向原有空间的话让指针指向现在的空间。
            num++;
        }
    }
    //开辟了多少次内存？ 18次
    cout<<"num="<<num<<endl;


}
int main()
{
    test01();
    return 0;
}