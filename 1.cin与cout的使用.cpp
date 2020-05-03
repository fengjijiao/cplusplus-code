#include <iostream>
#include <string>
using namespace std;
int main ( )
{
    int i, j;
    double d;
    string s;  // C++中新增 string 类型
    i = 10;
    d = 123.45;
    s = "http://see.xidian.edu.cn/cpp/biancheng/cpp/rumen/";
    cout << "请输入一个整数：";
    cin >> j;//输入j
    cout << "i=" << i << "\n";//"\n"与endl等价
    cout << "j=";//输出可以分开写也可以合并为1行，如下18行
    cout << j;
    cout << endl;
    cout << "d=" << d << endl;
    cout << s << endl;
    return 0;
}
