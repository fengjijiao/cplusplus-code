#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    void show() {
        cout << "BASE" << endl;
    }
};
class CDerive : public CBase {
public:
    void show() {
        cout << "DERIVE" << endl;
    }
};
int main ( )
{
    CDerive d;
    CBase& x = d;
    d.show();
    x.show();
    return 0;
}
/*
DERIVE
BASE
*/
/*
在19行时进行了强制类型转换，从CDerive ---> CBase
*/
