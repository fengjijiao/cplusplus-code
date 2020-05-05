#include <iostream>
#include <string>
using namespace std;
class CBase {
    string id;
    string name;
public:
    CBase(string s1, string s2) : name(s1), id("base-"+s2) { }
    void show() {
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
    }
};
class CDerive : public CBase {
    string id;
    int age;
public:
    CDerive(string s1, int a, string s2) : age(a), id("DERIVE-"+s2), CBase(s1, s2) { }
    void show() {
        cout << "id: " << id << endl;
        cout << "age: " << age << endl;
        //派生类的内部调用基类的方法
        CBase::show();
        //show();    //如果误写成这样，将不断地重复循环地调用自身(即死循环)。
    }
};
int main ( )
{
    CDerive d("C++", 3, "8503026");    //派生类的实例
    d.show();    //运行的是CDerive类的show()函数
    cout << "-------------"<< endl;
    //类的外部调用基类的方法
    d.CBase::show();    //运行的是CBase类的show()函数
    cout << "-------------"<< endl;
    CBase b("C", "8503026");    //基类当作普通类直接产生的实例
    b.show();    //运行的是CBase类的show()函数
    return 0;
}
/*
id: DERIVE-8503026
age: 3
name: C++
id: base-8503026
-------------
name: C++
id: base-8503026
-------------
name: C
id: base-8503026
 */
/*
基类和派生类都有成员变量“id”和成员函数“show()”，无论是在派生类的内部还是外部，直接调用的成员都是派生类的成员，而基类的成员函数show()未被调用。要调用基类成员，必须在成员函数名前加上范围(类名::)，这也适用于基类的成员变量。
 */
