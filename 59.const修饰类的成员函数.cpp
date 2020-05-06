#include <iostream>
using namespace std;
class classA {
    int x;
    string y;
public:
    void get(int& i, string& s) const {
        int k;
        k = 10;       //非成员变量可以修改
        //x = k;      //成员变量不能修改
        //y = "小雅"; //成员变量不能修改
        i = x, s = y;
    }
    void set(int i, string s) { x = i; y = s; }
};
int main ( )
{
    classA ca;
    ca.set(100, "C");
    int i;
    string s;
    ca.get(i, s);
    cout << s << "--" << i << endl;
    return 0;
}
//C--100
/*
用const修饰类的成员函数，可以使函数内不能对任何成员变量修改。不是成员变量当然可以修改。
 */
