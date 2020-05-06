#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    virtual void show() = 0;    //这是“纯虚函数”
    virtual void print() {      //这是普通的“虚函数”
        cout << "BASE PRINT" << endl;
    }
};
class CDerive : public CBase {
public:
    void show() {      //在派生类中，对“纯虚函数”必须实装
        cout << "DERIVE SHOW" << endl;
    }
};
int main ( )
{
    CDerive d;
    CBase& x = d;
    d.show(),  x.show();
    d.print(), x.print();
    //CBase b;     //抽象类不能实例化
    //b.show(),  b.show();
    return 0;
}
/*
DERIVE SHOW
DERIVE SHOW
BASE PRINT
BASE PRINT
*/
/*
虚继承的应用使程序设计发生了很大变化，也就是在设计阶段只定义基类，而编程阶段通过继承来完成真正的功能。为了控制基类的成员函数在基类什么也不做，引进了“纯虚函数”的概念，使之没有定义体，因而也就不能产生实例。包含“纯虚函数”的类，因不能产生实例，所以称之为“抽象类”。

Java程序员注意：在Java中有类似“抽象类”的称之为“接口”的类，在Visual C++中也有，但这不是标准C++的内容。
*/
