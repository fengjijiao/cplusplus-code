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
