#include <iostream>
using namespace std;
float fun(float x);
double fun(double x);
int main ( )
{
    float f = 132.64;
    double d = 132.64;
    cout << fun(f) << endl;
    cout << fun(d) << endl;
    //cout << fun(5) << endl;    //编译错，参数5可以转换为float，也可转换为double
    return 0;
}
float fun(float x)
{
    return x / 2.0 ;
}
/*
函数的重载在C++中具有重要作用，重载(overload)不要和后面要学的覆盖(override)混淆起来。重载是指相同的函数名，但参数的类型或个数中只要有所不同，便进行再定义，编译之后重载的函数都具有不同的地址，也就是说虽然函数名相同，实际上是不同的函数，在调用时，编译系统会根据不同之处自动区别是调用哪一个函数。对于普通函数和后面要学的类的成员函数都适用。

覆盖只对类的构造函数或成员函数适用，是子类继承父类是才使用的非常有用的功能。重载可以针对运算符，而覆盖不行。上一节中缺省值的设置，实际上在编译时等价于重载，被生成了4个不同的函数。

早期的C++版本，在定义重载函数时要加上关键字overload，现在不用了。在使用重载函数时，如果有类型的自动转换时要特别注意，初学者往往出错在这儿。
*/
double fun(double x)
{
    return x / 3.0;
}
/*
66.32
44.2133
*/
