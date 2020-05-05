#include <iostream>
#include <string>
using namespace std;
class CBase {
    string name;
public:
    CBase(string s) : name(s) {
        cout << "BASE: " << name << endl;
    }
    ~CBase() {
        cout << "~BASE" << endl;
    }
};
class CDerive : public CBase {
    int age;
public:
    CDerive(string s, int a) : CBase(s), age(a) {
        cout << "DERIVE: " << age << endl;
    }
    ~CDerive() {
        cout << "~DERIVE" << endl;
    }
};
int main ( )
{
    CDerive d("小雅", 27);
    return 0;
}
/*
BASE: 小雅
DERIVE: 27
~DERIVE
~BASE
 */
