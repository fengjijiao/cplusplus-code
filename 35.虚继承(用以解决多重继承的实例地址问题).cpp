#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    string id;
};
//因为虚继承，CBase类在此不产生副本
class CDerive1 : virtual public CBase {
public:
    void show1() {
        cout << "CDerive1: " << id << endl;
    }
};
//因为虚继承，CBase类在此不产生副本
class CDerive2 : virtual public CBase {
public:
    void show2() {
        cout << "CDerive2: " << id << endl;
    }
};
class CSon : public CDerive2, public CDerive1 { };
int main ( )
{
    CSon s;
    s.CDerive1::id = "WD8503026";
    s.CDerive2::id = "WD8503027";
    s.CBase::id = "WD8503025";
    s.show1();
    s.show2();
    cout << "BASE: " << s.CBase::id << endl;
    return 0;
}
//理论上新版c++也无法执行
/*
CDerive1: WD8503025
CDerive2: WD8503025
BASE: WD8503025
*/
//因为2个“父亲”都不产生“爷爷”的副本，所以“孙子”这儿就只有一个“爷爷”的副本。
