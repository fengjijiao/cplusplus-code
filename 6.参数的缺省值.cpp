#include <iostream>
using namespace std;
int sum(int x=0, int y=100, int z=0) { return x+y+z; }
//在C++中参数可以设置缺省值，设置了缺省值之后，这个参数在调用时可以省略。

注意：设置缺省值的参数只能是最后的几个参数。也就是说某一个参数一旦设置了缺省值，其后而的参数也必须设置缺省值。例如：f()函数有3个参数，如果只设置第2个有缺省值，这就错了。因为调用时只输入2个参数时，系统不知道究竟是第2个参数还是第3个参数。
//int sum(int x, int y=100, int z=0) { ... }   //这是正确的
//int sum(int x, int y, int z=0) { ... }       //这也是正确的
//int plus(int x, int y=100, int z) { ... }    //这是错误的
int main ( )
{
    cout << sum() << endl;
    cout << sum(6) << endl;
    cout << sum(6, 10) << endl;
    cout << sum(6, 10, 20) << endl;
    return 0;
}
/*
100
106
16
36
*/
