#include <iostream>
using namespace std;
// 子串获取
/*
从子串中获取想要的子串

string substr(int pos = e, int n = npos) const;
//返回由pos开始的n个字符组成的字符串
*/

void test01()
{
    string str1 = "qwertt";
    string subStr = str1.substr(1,3);
    cout<<"sybStr = "<<subStr<<endl;

}

void test02()
{
    //实用例子
    string email = "hello@qq.com";
    //从邮件中获取用户用户名信息
    int pos = email.find("@");
    string userName = email.substr(0,pos);
    cout<<"username="<<userName<<endl;
}
int main()
{
    test01();
    test02();
    return 0;
}