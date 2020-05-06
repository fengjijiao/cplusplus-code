#include <iostream>
using namespace std;
int main ( )
{
    int x = 12;
    int y = 25;
    //const int * const p4;    //编译出错，初始化必须赋值
    const int * const p4 = &x;
    //修改p4的地址，NG！
    //p4 = &y;      //地址不能被修改
    //修改p4指针的值，NG！
    //*p4 = 156;    //指针值不能被修改
    cout << "p4: " << *p4 << endl;
    //通过其它变量，间接地修改p4指针的值，OK！
    x = 123;
    cout << "p4: " << *p4 << endl;
    return 0;
}
/*
p4: 12
p4: 123
 */
/*
“const int * const p4”，这是前2种的结合，既不允许修改地址，也不允许修改内容。
 */
