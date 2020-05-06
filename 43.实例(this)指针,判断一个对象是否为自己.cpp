#include <iostream>
#include <string>
using namespace std;
class base {
public:
    void check(base *obj) {
        if (obj == this) {
            cout << "这是当前的对象"  << endl;
        } else {
            cout << "这不是同一个对象"  << endl;
        }
    }
};
class derive : public base {
public:
    base *getBase() {
        base *p = this;   //强制转换成父类的地址
        return p;          //返回父类地址
    }
};
int main ( )
{
    base ba;
    derive de;
    //base *p1 = de.getBase();    //取基类地址
    base p1 = de;
    base *p2 = &ba;
    ba.check(&p1);
    ba.check(p2);
    return 0;
}
/*
这不是同一个对象
这是当前的对象
 */
/*
对象（即实例）可以通过参数传来传去，有时需要判断一下用对象是否与自己是同一实例，可以用“if (&obj == this) { ... }”
 */
