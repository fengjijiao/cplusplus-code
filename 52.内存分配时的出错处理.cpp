#include <iostream>
#include <new>
using namespace std;
int main ( )
{
    //判断指针是否为NULL
    double *arr = new double[100000];
    if (!arr) {
        cout << "内存分配出错！" << endl;
        return 1;
    }
    delete []arr;
    //例外出错处理
    try {
        double *p = new double[100000];
        delete []p;
    } catch (bad_alloc xa) {
        cout << "内存分配出错！" << endl;
        return 1;
    }
    //强制例外时不抛出错误，这时必须要判断指针
    double *ptr = new(nothrow) double[100000];
    if (!ptr) {
        cout << "内存分配出错！" << endl;
        return 1;
    }
    delete []ptr;
    cout << "内存分配成功！" << endl;
    return 0;
}
//内存分配成功！
/*
一般有2种处理方法，一是根据指针是否为空来判断，一是用例外出错处理所抛出的“bad_alloc”来处理。
 */
