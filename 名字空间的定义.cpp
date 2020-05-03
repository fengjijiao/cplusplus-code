#include <iostream>
using namespace std;
//使用 namespace声明名字空间，使用::指定所属的名字空间
namespace na
{
    void print(int n) {     //与名字空间nb的函数名相同
        cout << "na::print: " << n << endl;
    }
}
namespace nb
{
    void print(int n) {     //与名字空间na的函数名相同
        cout << "nb::print: " << n << endl;
    }
}
namespace na  // 同一个名字空间可以定义多次
{
    void print2(int a, int b) {
        print(a);
        print(b);
    }
}
int main ( )
{
    na::print(3);        // 指定na下的print函数
    nb::print(4);        // 指定na下的print函数
    na::print2(5, 6);    // 指定na下的print2函数
    return 0;
}
/*
na::print: 3
nb::print: 4
na::print: 5
na::print: 6
*/
