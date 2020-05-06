#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    virtual void show() {
        cout << "BASE SHOW" << endl;
    }
    virtual void print() {
        cout << "BASE PRINT" << endl;
    }
};
class CDerive : public CBase {
public:
    void show() {
        cout << "DERIVE SHOW" << endl;
    }
};
int main ( )
{
    CDerive d;
    CBase& x = d;
    d.show(),  x.show();    //虚函数只影响派生类的实装
    d.print(), x.print();
    CBase b;
    b.show(),  b.print();   //虚函数不影响基类自身的实例
    return 0;
}
/*
DERIVE SHOW
DERIVE SHOW
BASE PRINT
BASE PRINT
BASE SHOW
BASE PRINT
*/
/*
解决上个问题很简单，基类中的show()函数改成虚函数，在派生类中用同名函数“实装”基类的虚函数。如果派生类中没有同名函数，则仍用基类的虚函数实装。
*/
/*
注意：“虚继承”和“虚函数”是二个不同概念，“虚继承”针对基类的成员变量的二义性，而“虚函数”是针对成员函数的二义性。“虚继承”是将“virtual”加在派生类的定义处，“虚函数”是将“virtual”加在基类的成员函数的定义处。
*/
