#include <iostream>
using namespace std;
class classB {
    int x;
public:
    classB(int x) { this->x = x; }
    int getB() { return x; }
};
class classA {
    classB xb;
public:
    //classA(classB b) { xb = b; }    //编译出错
    classA(classB b) : xb(b) { }     //只能用这种方法
    int setX() { return xb.getB(); }
};
int main ( )
{
    classB cb(5);    //先定义一个classB的实例
    classA ca(cb);  //然后用这个实例创建classA的实例
    cout << "x = " << ca.getX() << endl;
    return 0;
}
//x=5
/*
当一个类的成员变量的类型是另一个类时，称之为“合成(composite)”。构造函数在对这个变量赋值时，不能在函数体里面赋值，只能用创建时赋值。
*/
