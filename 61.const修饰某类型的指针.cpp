#include <iostream>
using namespace std;
int main ( )
{
    int x = 12;
    int y = 25;
    char c = 'D';
    const int * p1;
    //新分配一块int型空间，再将p1指向新空间作为常量，OK！
    p1 = new int(100);
    cout << "p1: " << *p1 << endl;
    delete p1;
    //将p1指向非int型变量作为常量，NG！
    //p1 = &c;    //类型不匹配
    //将p1指向int型变量作为常量，OK！
    p1 = &x;
    //*p1 = 22;//内容不能改变
    cout << "p1: " << *p1 << endl;
    //修改p1的地址，OK！
    p1 = &y;        //地址可以被修改
    cout << "p1: " << *p1 << endl;
    //修改p1指针的值，NG！
    //*p1 = 156;    //指针值不能被修改
    //通过其它变量，间接地修改p1指针的值，OK！
    y = 158;
    cout << "p1: " << *p1 << endl;
    return 0;
}
/*
p1: 100
p1: 12
p1: 25
p1: 158
 */
/*
“const int * p1”，p1是指向int型的指针变量，然后再作为常量。变量的地址可以改变，但内容不能改变，类型也必须一致。
 */
