#include <iostream>
using namespace std;
//使用 namespace声明名字空间，使用::指定所属的名字空间
//使用“using namespace”可以使得后面不需要每次指定名字空间，相当于java中的import功能。不过，多次使用“using namespace”时，被指定的名字空间同时有效，很容易冲突。
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
