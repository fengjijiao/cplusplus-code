#include <iostream>
using namespace std;
typedef const double CONSTANT;//相当于const double == CONSTANT
CONSTANT pi = 3.14159265;
struct mytype {
    const int x;
    int y;
};
int main ( )
{
    //pi = 3.14;    //编译出错，常量不能赋值

    //常量定义必须有初始值
    //mytype s;    //编译出错，结构体中的x成员常量没有初始值
    mytype s1 = {15, 20};
    //s1.x = 3     //编译出错，常量不能赋值
    s1.y = 100;
    const mytype s2 = {25, 30};
    //s2.y = 125;  //编译出错，整个s2的所有成员都变成了常量
    cout << "s1: " << s1.x << ", " << s1.y << endl;
    cout << "s2: " << s2.x << ", " << s2.y << endl;
    return 0;
}
/*
s1: 15, 100
s2: 25, 30
 */
//C语言也支持const
/*
在C++中，一般用const完全替代C语言的define，且功能更多。用const修饰变量，使之成为常量（或常数），这很简单，但结构体中成员如果用了const，需要注意
 */
