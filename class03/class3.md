# c++提高变成：泛型编程和STL

# 1.模板

## 1.1模板的概念

模板的概念：建立通用模具，大大提高复用性

模板的特点：

* 1.模板不可以直接使用，只是一个框架 

* 2.模板的通用不是万能的

## 1.2 函数模板

### 1.2.1函数模板语法

1. 函数模板作用：建立一个通用函数，其函数返回类型和形参类型可以不具体指定 用一个虚拟的类型来代表。

2. 语法：template<typename T>   换行 函数声明和定义

template --声明创建模板  

typename--表面器后面的符号是一种数据类型 可以用class代替  

T--通用数据类型 ，名称可替换，通常为大写字母。

```c++
template<typename T>//声明一个模板 告诉编译器 后面代码中紧跟的T不要报错，T是一个通用数据类型。
void mySwap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
```

3. 函数模板有两种方式使用

  (1.)自动类型推导

```cpp
  mySwap(a,b);
```

 () 2.)显示指定类型

```cpp
  mySwap<int>(a,b);
```



### 1.2.2函数模板注意事项

注意事项:

* 1.自动类型推导：必须推导出一致的数据类型才能使用

* 2.模板必须要确定出T 的数据类型才可以使用

### 1.2.3函数模板案例（实现通用对数组排序的函数）

要求：

1。利用函数模板封装一个排序函数，可以对不同数据类型数组进行排序

2.利用规则从大到小，选择排序

3,测试:char数组和int数组

解决：

两数交换模板函数、排序函数模板、打印函数模板

### 1.2.4 普通函数与函数模板的区别

1.普通函数调用可以发生隐式类型转换

2.函数模板 用自动类型推导 不可以发生隐式类型转换

3.函数模板用显示指定类型，可以发生隐式类型转换



### 1.2.5普通函数和函数模板调用规则

1.如果函数模板和普通函数都可以实现 优先调用普通函数。

2.可以通过 空模板参数列表 来强制调用函数模板

```cpp
myPrint<>(a,b); //第二个规则测试
```

3.函数模板也可以重载

4.如果函数模板可以产生更好的匹配，优先调用函数模板



## 1.3类模板

### 1.3.1类模板语法

作用: 建立一个通用的类,类中的成员数据类型可以不具体制定,用一个虚拟的 类型来代表.

语法相似 在template下一行跟一个类就是类模板

```cpp
template<class NameType,class AgeType>
class Person
{
    public:
    Person(NameType name,AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout<<"name:"<<this->m_Name<<" age:"<<this->m_Age<<endl;
    }
    NameType m_Name;
    AgeType m_Age;
};
```

```CPP
Person<string,int> p1("sunwukomh",999);
```

### 1.3.2类模板与函数模板的区别

1.类模板没有自动类型推导的使用方式

2.类模板在模板参数列中中可以有默认参数(只有类模板可以 函数模板不可以)

```CPP
template<class NameType,class AgeType = int>
```

### 1.3.3类模板中的成员函数创建时机

类模板中的成员函数并不是一开始就创建的,在调用时才会创建

```cpp
template<class T>
class MyClass
{
    public:
    T obj;
    // 类模板中的成员函数 一开始编译器不会去 调用才会编译
    void fun1()
    {
        obj.showPerson1();
    }
    void fun2()
    {
        obj.showPerson2();
    }

};
```

### 1.3.4类模板对象做函数参数

三种传递方式

1.指定传入的类型(注意：最常用、使用最广泛)

```cpp
void printPerson1(Person<string,int>&p)
```

2.参数模板化

```cpp
template<class T1,class T2>

void printPerson2(Person<T1,T2>&p)
```

3.整个类模板化

```cpp
template<class T>

void printPerson3(T &p)
```

### 1.3.5类模板与继承

1.当子类继承父类是类模板时,子类在声明的时候,要指定出父类中的T的类型

```cpp
class Son: public Base<int>
```

2.如果不指定,编译器无法给子类分配内存

3.如果想灵活指出父类中的T类型,子类也需要变为类模板

```cpp
template<class T1, class T2>
class Son2:public Base<T2>
```

### 1.3.6类模板成员函数类外实现

总结:类模板中成员函数类外实现时,需要加上模板参数列表.

```cpp
// 构造函数的类外实现
template<class T1,class T2>
class Person
{
    public:
    Person(T1 name, T2 age);
    void showPerson();
   	public:
    T1 m_Name;
    T2 m_Age;
};
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
        this->m_Name = name;
        this->m_Age = age;
}
template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
    cout<<"姓名:"<<this->m_Name<<" 年龄"<<this->m_Age<<endl;
}
```

### 1.3.7类模板的分文件编写

* 学习目标:掌握类模板成员函数分文件编写产生的问题及解决方式

* 问题:类模板中成员函数创建时机是在调用阶段,导致分文件编写时链接不到

* 解决:
* 解决方式1:直接包含.cpp源文件

.h文件中写类的定义

.cpp文件中写类的方法 .cpp的头文件包含#include<lei.h>

所以直接在main所在文件中直接头文件声明#include<类名.cpp>(但是一般不这样写)

* 解决方式2:将声明和实现写在同一文件中,并更改后缀为.hpp,hpp是约定名称,并不是强制

直接将类和类的函数类内声明类外定义都写到一个文件中，文件后缀为.hpp

### 1.3.8类模板与友元

1.掌握类模板配合友元函数的类内和类外实现

2.全局函数类内实现:直接在类内生命友元即可

```cpp
template<class T1,class T2>
class Person
{
    // 全局函数 类内实现
    friend void printPerson(Person<T1,T2> p )
    {
        cout<<"name:"<<p.m_Name<<" age:"<<p.m_Age<<endl;
    }
    ///省略
}
```

3.全局函数类外实现:需要提前让编译器知道全局函数的存在

```cpp
template<class T1,class T2>
class Person; //person又是个模板 需要再提前声明模板

// 全局函数类外实现  需要让编译器提前知道这个函数的存在 提前知道这个函数就需要声明一下person类
template<class T1,class T2>
void printPerson2(Person<T1,T2> p ) //函数模板实现
{
    cout<<"类外实现:name:"<<p.m_Name<<" age:"<<p.m_Age<<endl;
}

template<class T1,class T2>
class Person
{
    //全局函数类外实现  需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1,T2> p );  //普通函数声明
    ///省略
}
```

4.调用

```cpp
Person<string,int> p("tom",20);
printPerson(p);
```

# 2.STL

## 2.1 STL的诞生

长久以来，软件结希望建立一种可重复利用的东西

c++面向对象和泛型编程思想，目的提升复用性

大多数情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复的工作

为了建立数据结构和算法的一套标准，诞生了STL

## 2.2 STL基本概念

STL(Standard Template Library,标准模板库)

STL广义上分为：容器container 算法algorithm 迭代器iterator

容器和算法之间通过迭代器进行无缝连接

STL几乎所有代码都采用模板类或模板函数

## 2.3 STL六大组件

STL大体

分为六大组件：容器、算法、迭代器、防函数、适配器、空间配置器。

1.容器：各种数据结构，如vector、list、deque、set、map

2.算法：sort、find、copy、for_each

3.迭代器：容器与算法的胶合剂

4.仿函数：行为类似于函数，可以作为算法的某种策略

5.适配器：一种用来修饰容器或者仿函数或者迭代器接口的东西

6.空间配置器：负责空间的配置和管理

## 2.4 STL容器、算法、迭代器

*容器*：

置物之所也

STL容器就是运用最广泛的一些数据结构实现出来

常用的数据结构：数组、链表、树、栈、队列、集合、映射表

容器分为：序列式容器、关联式容器

序列式容器：强调值的排序，序列式容器中每个元素均有固定的位置

关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

*算法*：

有限的步骤解决逻辑或数学上的问题

算法分为：质变算法和非质变算法

质变算法：指运算过程中会更改区间内的元素的内容，如拷贝、替换、删除等

非质变算法：指运算过程中不会更改区间内元素的内容，如查找、计数、遍历、寻找极值等。

*迭代器*：

容器和算法的粘合剂

提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴漏该容器的内部表示方式。

每个容器都有自己专属的迭代器

迭代器类似指针，初学可理解为指针。

迭代器种类

| 种类           | 功能                                                   | 支持运算                                |
| -------------- | ------------------------------------------------------ | --------------------------------------- |
| 输入迭代器     | 对数据的只读访问                                       | 只读、支持++、 ==、 ！=                 |
| 输出迭代器     | 对数据的只写访问                                       | 只写，支持++                            |
| 前向迭代器     | 读写操作、并能向前推进迭代器                           | 读写、支持++、==、！=                   |
| 双向迭代器     | 读写操作、并能向前和向后操作                           | 读写，支持++、--                        |
| 随机访问迭代器 | 读写操作、可以以跳跃方式访问任意数据，功能最强的迭代器 | 读写，支持++、--、[n]、-n、<、<=、>、>= |

常用的容器中迭代器种类为双向迭代器，和随机访问迭代器

## 2.5 容器算法迭代器初识

STL中最常用的容器Vector，可以理解为数组，插入、遍历数据

### 2.5.1 vector存放内置数据类型

容器：vector

算法：for_each

迭代器：vector<int>::iterator

```cpp
vector<int>::iterator itBegin = v.begin(); //起始迭代器 指向容器中的第一个元素 

vector<int>::iterator itEnd = v.end(); //结束迭代器 指向最后一个元素的下一个位置
```



### 2.5.2 Vector存放自定义数据类型

1.存放自定义数据类型定义：

```cpp
vector<Person> v;
Person p1("aaa",12);
```

// 像容器中添加数据

```cpp
 v.push_back(p1);
```

// 遍历容器中的数据

```cpp
 for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"name:"<<(*it).m_Name<<" age:"<<(*it).m_Age<<endl;
        // cout<<"name:"<<it->m_Name<<" age:"<<it->m_Age<<endl;
    }
```

2.存放自定义指针数据类型

```cpp
vector<Person*> v;
Person p1("aaa",12);
```

// 像容器中添加数据

```
v.push_back(&p1);
```

// 遍历容器中的数据

```cpp
// 遍历容器
        for(vector<Person*>::iterator it=v.begin(); it!=v.end();it++)
        {
            cout<<"name:"<<(*it)->m_Name<<" age:"<<(*it)->m_Age<<endl;
        }
```

### 2.5.3vector容器嵌套容器

```cpp
void test01()
{
    vector<vector<int>>v;
    // 创建4个小容器
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
    // 给小容器中添加数据
    for(int i=0;i<4;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    // 将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    // 通过大容器遍历所有数据
    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
    {
        // (*it) --是容器 vector<int>
        for(vector<int>::iterator vit=(*it).begin(); vit!=(*it).end();vit++)
        {
            cout<<*vit<<" ";

        }
        cout<<endl;

    }
```



# 3.STL常用容器

# 3.1 string容器

### 3.1.1 string基本概念

本质：string是c++风格的字符串，string本质是一个类

string和char*区别：

char*是一个指针

string是一个类，类内部封装了char*管理这个字符串，是一个char*型容器

特点：

string类内部封装了很多成员方法

例如：find、copy、delete、insert

string管理char*所分配的内存，不用担心复制越界等，由类内部进行负责

### 3.1.2string构造函数

string构造函数原型

| string();                  | 创建一个空的字符串                                   | string s1;         |
| -------------------------- | ---------------------------------------------------- | ------------------ |
| string(const char* s);     | 使用字符串s初始化                                    | string s2 (str);   |
| string(const string& str); | 使用一个string对象初始化另一个string对象（拷贝构造） | string s3(s2);     |
| string(int n, char c);     | 使用n个字符c初始化                                   | string s4(10,'a'); |



### 3.1.3string赋值操作

等号赋值较为实用



## 3.2 vector容器

## 3.2.1 vector基本概念
- 功能:
  vector数据结构和数组非常相似，也称为单端数组
- vector与普通数组区别:
  。不同之处在于数组是静态空间，而vector可以动态扩展
- 动态扩展:
  并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

![image-20231008164515985](C:\Users\大太阳\AppData\Roaming\Typora\typora-user-images\image-20231008164515985.png)

### 3.2.2 vector构造函数

- 功能描述:
  创建vector容器

- 函数原型:

  | vector<T> v;                 | 采用模板实现类实现，默认构造函数                      |      |
  | ---------------------------- | ----------------------------------------------------- | ---- |
  | vector(v.begin()， v.end()); | 将v[begin(),end()）（前闭后开）区间中的元素拷贝给本身 |      |
  | vector(n,elem);              | 构造函数将n个elem拷贝给本身                           |      |
  | vector(const vector &vec);   | 拷贝构造函数                                          |      |

  

### 3.2.2 vector构造函数

- 功能描述:
  给vector容器进行赋值

- 函数原型:

  | vector& operator=(const vector &vec); | 重载等号操作符                        |      |
  | ------------------------------------- | ------------------------------------- | ---- |
  | assign(beg，end);                     | /将[begend)区间中的数据拷贝财值给本身 |      |
  | assign(n, elem);                      | /将n个elem拷贝赋值给本身。            |      |

### 3.2.4 vector容量和大小

- 功能描述:
  。对vector容器的容量和大小操作

- 函数原型:

  | empty();               | 判断容器是否为空                                             |      |
  | ---------------------- | ------------------------------------------------------------ | ---- |
  | capacity();            | 容器的容量                                                   |      |
  | size();                | 返回容器中元素的个数                                         |      |
  | resize(int num);       | 重新指定容器的长度为num，若容器变长，则以默认值填充新位置<br/>//如果容器变短，则末尾超出容器长度的元素被删除。 |      |
  | resize(int num, elem); | //重新指定容器的长度为num，若容器变长，则以elem值填充新位置.<br/>//如果容器变短，则末尾超出容器长度的元素被删除 |      |



### 3.2.5vector的插入和删除

- 功能描述:
  对vector容器进行插入、删除操作

- 函数原型:

  | push back(ele);                                  | 尾部插入元素ele                                             |      |
  | ------------------------------------------------ | ----------------------------------------------------------- | ---- |
  | pop_back();                                      | 删除最后一个元素                                            |      |
  | insert(const iterator pos, ele);                 | 迭代器指向位置pos插入元素ele                                |      |
  | insert(const_iterator pos，int count,ele);       | //选代器指向位置pos插入count个元素ele//删除迭代器指向的元素 |      |
  | erase(const_iterator start，const_iterator end); | 删除选代器从start到end之间的元素                            |      |
  | erase(const iterator pos);                       | 删除容器中所有元素                                          |      |
  | clear();                                         | 删除容器中所有元素                                          |      |






### 3.2.7 互换容器

- 功能描述:

实现两个容器内元素进行互换

- 函数原型:

swap(vec); // 将vec与本身的元素互换

- 实际应用：  收缩内存

```cpp
 vector<int>(v).swap(v);
```

vector<int>(v)//匿名对象

创建一个匿名对象和v调换，，匿名对象之这行代码执行完之后由系统回收。

### 3.2.8 预留空间

- 功能描述:

减少vector在动态扩展容量时的扩展次数

- 函数原型:

reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问。

```cpp
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
```

