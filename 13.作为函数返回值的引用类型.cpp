#include <iostream>
using namespace std;
int &f();
int x;
int main ( )
{
    f() = 100;//f=100;(f为引用类型的变量)
    cout << x << endl;
    return 0;
}
int &f()//== int &f=x;(int &仅表示引用类型)
{
    return x;
}
/*
 * 上面这个函数的返回值是引用类型，通过函数结果的设置反过来去改变“源头”数据，这种“逆向引用”为C++增强了很多功能，当然也有许多需要注意的地方
 */
