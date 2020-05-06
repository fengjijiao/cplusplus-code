#include <iostream>
#include <string>
using namespace std;
class ca {
    string id;
    void setId(string s) {
        id = s;
    }
protected:
    string name;
    void setName(string s) {
        name = s;
    }
public:
    void print() {
        cout << id << "  " << name << "  " << endl;
    }
    friend void fun(ca& a);    //申明全局函数作友元，允许它访问私有保护成员
};
class derive : public ca { };    //ca类的派生类
void fun(ca& a) {        //作友元的函数要定义在那个类的后面
    a.id = "987";        //这是ca类的私有成员
    a.setName("xyz");    //这是ca类的保护成员
}
int main ( )
{
    ca a;
    //a.fun(...);    //友元函数不是当前类的成员函数，所以这句编译出错
    fun(a);
    a.print();
    derive d;
    fun(d);    //作参数时，类型转换为ca类
    d.print();
    return 0;
}
/*
987  xyz
987  xyz
 */
/*
类的外部，也就是通过实例来访问私有(private)或保护(protected)成员，这是被禁止的。但从实用性来说，的确有时很需要在外部访问，C++增加了一种称之为“友元(friend)”函数的申明，将“特权”赋给一些函数(可以是全局函数，也可以是其它类的成员函数)，使之能够访问该类的私有和保护成员。

友元函数必须在类里面申明，而且友元函数一定不是该类的成员函数。因此，这样的“特权”实际上已经不是完全的面向对象设计了，当然，我们也可以不用它。另外，友元函数的申明在派生类无效，除非派生类中再申明一次，当然类型转换为基类时，使用没有任何问题。
 */
/*
要使用全局函数作友元函数，也就是说全局函数中要使用当前这个类的实例，因此，全局函数的定义必须放在这个类的后面，否则，编译时这个类的实例就成了未定义的数据类型了。
 */
