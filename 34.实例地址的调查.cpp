#include <iostream>
#include <string>
using namespace std;
class CBase {
    string id;
public:
    void show() {
        cout <<  id << endl;
    }
};
class CDerive1 : public CBase { };
class CDerive2 : public CBase { };
class CSon : public CDerive2, public CDerive1 { };
int main ( )
{
    CSon s;
    cout <<  &s << endl;
    cout <<  "---------" << endl;
    CDerive1 *pd1 = &s;
    cout <<  pd1 << endl;
    CDerive2 *pd2 = &s;
    cout <<  pd2 << endl;
    cout <<  "---------" << endl;
    CBase *pb1 = pd1;
    cout <<  pb1 << endl;
    CBase *pb2 = pd2;
    cout <<  pb2 << endl;
    //CBase *pb = &s;    //编译有错
    return 0;
}
/*
0035FB20
---------
0035FB3C
0035FB20
---------
0035FB3C
0035FB20
*/
/*
先定义一个“孙子”的实例，并将地址输出。再将这个实例的地址分别赋给CDerive1和CDerive2类型的指针变量，并输出指针地址。再将这2个地址分别赋给CBase的2个指针变量，并输出其地址。
*/
/*
从上例可以看出，由于2个“父亲”因而复制出2个“爷爷”，2个“爷爷”的地址也不同。
*/
