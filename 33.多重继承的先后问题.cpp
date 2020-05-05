#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    string id;
};
class CDerive1 : public CBase {
public:
    void show1() {
        cout << "CDerive1: " << id << endl;
    }
};
class CDerive2 : public CBase {
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
    s.CBase::id = "WD8503025";//在新版c++上存在错误
    /*
     * Ambiguous conversion from derived class 'CSon' to base class 'CBase': class CSon -> class CDerive2 -> class CBase class CSon -> class CDerive1 -> class CBase
     */
    s.show1();
    s.show2();
    cout << "BASE: " << s.CBase::id << endl;//在新版c++上存在错误
    return 0;
}
/*
可能由于c++版本原因，以上代码无法运行
*/
/*
通过设置断点不难看出，当前实例是CBase的“孙子”，而“父亲”有2个，每个“父亲”都将“爷爷”复制了一份。如果不指定哪个“父亲”的“父亲”，默认将第一个继承的“父亲”的“父亲”当作“爷爷”。上例中先继承CDerive2类，所以31行和34行的“s.CBase::id”等价于“s.CDerive2::CBase::id”。
*/
