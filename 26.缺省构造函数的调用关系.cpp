#include <iostream>
#include <string>
using namespace std;
class CBase {
    string name;
    int age;
public:
    CBase() {
        cout << "BASE" << endl;
    }
    ~CBase() {
        cout << "~BASE" << endl;
    }
};
class CDerive : public CBase {
public:
    CDerive() {
        cout << "DERIVE" << endl;
    }
    ~CDerive() {
        cout << "~DERIVE" << endl;
    }
};
int main ( )
{
    CDerive d;
    return 0;
}
/*
BASE
DERIVE
~DERIVE
~BASE
 */
/*
基类与派生的构造函数的调用顺序。创建时先基类后派生类。销毁时先派生类后基类。
 */
