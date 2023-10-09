#include <iostream>
using namespace std;
// 3.1.1string的构造
void test01()
{
    string s1; //创建空字符
    const char *str = "hello world";
    string s2 (str);
    cout<<"s2= "<<s2<<endl;
    string s3(s2);
    cout<<"s3= "<<s3<<endl;
    string s4(10,'a'); //10个a创建字符串
    cout<<"s4= "<<s4<<endl;

}
int main()
{
    test01();
    return 0;
}