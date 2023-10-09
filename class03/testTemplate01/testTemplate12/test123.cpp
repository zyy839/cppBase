#include <iostream>
using namespace std;
// 1.2.3函数模板案例（实现通用对数组排序的函数）
// 1。利用函数模板封装一个排序函数，可以对不同数据类型数组进行排序
// 2.利用规则从大到小，选择排序
// 3,测试:char数组和int数组

// 交换函数模板
template<class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 排序算法
template<class T>
void mySort(T arr[],int len)
{
    for(int i = 0;i<len;i++)
    {
        int max = i; //认定最大值的下标
        for(int j = i+1;j<len;j++)
        {
            // 认定的最大值比遍历出的数值小,说明j下表的元素才是真正的最大值
            if(arr[max]<arr[j])
            {
                max = j;//更新最大值下标
            }
        }
        if(max!=i)
        {
            mySwap(arr[max],arr[i]);
        }
    }
}
// 遍历打印模板
template<class T>
void myPrint(T arr[],int len)
{
    for(int i = 0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void test01()
{
    // 测试char数组
    char charArr[] = "badkka";
    int num = sizeof(charArr)/sizeof(charArr[0]);
    mySort(charArr,num);
    myPrint(charArr,num);

    // 测试int数组
    int intArr[] = {24,25,1,2,5,25,2};
    int num2 = sizeof(intArr)/sizeof(intArr[0]);
    mySort(intArr,num);
    myPrint(intArr,num);



}
int main()
{
    test01();
    return 0;
}