/*
“拷贝构造函数”和“赋值运算符”都是将对象的值复制一份然后传给另一对象。这二个功能也是类本身就具有的，但有很多场合原封不动地复制给另外一个对象时反而会出错，例如在成员函数中有动态分配内存，或者参数指针指向外部某一地址时，就有可能出错。

要避免这些错误，我们可以重载“=”运算符以及拷贝构造函数，将出错的因素排除。下例中为了演示，故意将赋值运算符重载函数中不复制“姓名”，而拷贝构造函数中固定“年龄”。
*/
#include <iostream>
#include <string>
using namespace std;
class stuff {
    string name;
    int age;
public:
    stuff(string n, int a):name(n),age(a)
    {
        cout << "构造函数  " << name << age << endl;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    stuff& operator =(stuff& x);    //赋值运算符重载
    stuff(stuff& x):name(x.name),age(20)    //拷贝构造函数重载
    {
        cout << "拷贝构造函数  " << name << age << endl;
    }
};
stuff& stuff::operator =(stuff& x)
{
    age = x.age;
    cout << "赋值运算符  " << name << age << endl;
    cout << "新stuff的地址：" << &(*this) << endl;
    return *this;
}
int main ( )
{
    stuff st("C++", 3);     //调用通常的构造函数
    cout << "st 地址：" << &st << endl;
    stuff st1("C", 2);   //调用通常的构造函数
    cout << "st1 地址：" << &st1 << endl;
    st1 = st;         //因为不产生新的实例，所以调用的是赋值运算符
    //st1 = stuff&, 
    cout << "st1 地址：" << &st1 << endl;
    stuff st2 = st;   //因为产生新的实例，所以调用的是拷贝构造函数
    cout << "st2 地址：" << &st2 << endl;
    cout << st.getName() << st.getAge() << endl;
    cout << st1.getName() << st1.getAge() << endl;
    cout << st2.getName() << st2.getAge() << endl;
    int a;
    int &b = a;
    cout << &a << " " << &b << endl;
    int c = b;
    cout << &c << endl;
    return 0;
}
//注意：=:产生新的实例调用的是拷贝构造函数，不产生新的实例则调用赋值运算符
/*
构造函数  C++3
构造函数  C2
赋值运算符  C3
拷贝构造函数  C++20
C++3
C3
C++20
 */
