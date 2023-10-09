#include <iostream>
using namespace std;
#include<deque>
// deque构造函数
/*


*/
// void printDeque(deque<int>&d)
// {
//     // 这段代码中容器内数据可以修改 
//     for(deque<int>::iterator it = d.begin();it!=d.end();it++)
//     {
//         *it = 100;
//         cout<<*it<<" ";
//     }
//     cout<<endl;


   
// }

//容器内数据不可修改
void printDeque(const deque<int>&d)
{
   
    for(deque<int>::const_iterator it = d.begin();it!=d.end();it++)
    {
        //*it = 100; 报错 不可修改
        cout<<*it<<" ";
    }
    cout<<endl;
    
}

void test01()
{

 
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
    d1.push_back(i);
    }

    printDeque(d1);
  
    deque<int>d2(d1.begin(),d1.end());
    printDeque(d2);
    
    deque<int>d3(10,100);
    printDeque(d3);

    deque<int>d4(d3);
    printDeque(d4);
}
int main()
{
    test01();
    return 0;
}