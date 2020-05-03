#include <iostream>
using namespace std;
namespace na {
    namespace {     //无名名字空间
    //名字空间的名字也可以省略，称之为“无名名字空间”，无名名字空间经常被使用，其作用是“内部可以引用，而外部不能引用”。
        int sum(int a, int b)
        {
            return a + b;
        }
    }
    int calc(int x, int y)
    {
        return sum(x, y);  //内部可以调用无名名字空间的变量或函数
    }
}
int main ( )
{
    //cout << na::sum(5, 11) << endl;  //因为缺少里面的名字，所以外部不能调用
    cout << na::calc(6, 12) << endl;
    return 0;
}
