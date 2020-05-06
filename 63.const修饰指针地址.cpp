#include <iostream>
using namespace std;
int main ( )
{
    int x = 12;
    int y = 25;
    //int * const p3;    //编译出错，初始化必须赋值
    int * const p3 = &x;
    //新分配一块int型空间，再将p3指向新空间作为常量，NG！
    //p3 = new int(100);
    //修改p3的地址，NG！
    //p3 = &y;      //地址不能被修改
    //修改p3指针的值，OK！
    *p3 = 156;      //指针值可以被修改
    cout << "p3: " << *p3 << endl;
    return 0;
}
/*
p3: 156
 */
/*
“int * const p3”，p3是指针变量，其地址作为常量并指针限制为int类型。变量的地址不可以改变，但内容可以改变。定义时必须同时赋初始值。
 */
