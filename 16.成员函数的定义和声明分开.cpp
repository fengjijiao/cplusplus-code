//==test.h==
class CA {
    void a;
public:
    CA();
    ~CA();
    void setA(int x);
    void print();
};
//==test.cpp==
#include <iostream>
#include "test.h";
using namespace std;
CA::CA(){
    a = 0;
    cout << "构造函数： " << a << endl;
}
CA::~CA(){
    cout << "析构函数： " << a << endl;
}
void CA::setA(int x) {
    a = x;
}
void CA::print() {
    cout << "print： " << a << endl;
}
int main ( )
{
    CA ca;
    //ca.a = 10;    //成员变量a是私有的，不能直接访问
    ca.setA(10);
    ca.print();
    return 0;
}
/*
构造函数：0
print：10
析构函数：10
*/
/*
上面例子是将成员函数的定义和声明全写在类的定义体里面，更好的编程风格是分开来写，也就是类定义体里面只写成员变量和成员函数的声明，而成员函数的定义则写在类的定义体外。这样，类的定义体就可以移到“头文件”中去。在外部定义时，成员函数名前面要加上“类名::”。
*/
