#include <iostream>
using namespace std;
int main ( )
{
    int x = 12;
    int y = 25;
    char c = 'D';
    int const * p2;
    //新分配一块int型空间，再将p2指向新空间作为常量，OK！
    p2 = new int(100);
    cout << "p2: " << *p2 << endl;
    delete p2;
    //将p2指向非int型变量作为常量，NG！
    //p2 = &c;    //类型不匹配
    //将p2指向int型变量作为常量，OK！
    p2 = &x;
    cout << "p2: " << *p2 << endl;
    //修改p2的地址，OK！
    p2 = &y;        //地址可以被修改
    cout << "p2: " << *p2 << endl;
    //修改p2指针的值，NG！
    //*p2 = 156;    //指针值不能被修改
    //通过其它变量，间接地修改p2指针的值，OK！
    y = 158;
    cout << "p2: " << *p2 << endl;
    return 0;
}
/*
p2: 100
p2: 12
p2: 25
p2: 158
 */
/*
“int const * p2”，p2是指针变量，然后再作为常量并限制为int类型。变量的地址可以改变，但内容不能改变，类型也必须一致。

许多书上都说，这和“const int * p1”不一样，但究竟哪儿不一样却不说明。
 */
