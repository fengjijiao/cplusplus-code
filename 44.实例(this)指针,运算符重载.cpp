#include <iostream>
#include <string>
using namespace std;
class rect {
    int x1, y1, x2, y2;    //矩形座标
public:
    rect() {
        x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    }
    rect(int m1, int n1, int m2, int n2) {
        x1 = m1, y1 = n1, x2 = m2, y2 = n2;
    }
    void print() {
        cout << "  x1=" << x1;
        cout << "  y1=" << y1;
        cout << "  x2=" << x2;
        cout << "  y2=" << y2;
        cout << endl;
    }
    rect operator++(int) {//详见19.运算符重载 ++()：表示++j,++(int):表示j++
        x1++, y1++, x2++, y2++;
        return *this;    //返回当前实例
    }
};
int main ( )
{
    rect r(12, 20, 50, 40);
    r.print();
    rect obj;
    obj = r++;
    obj.print();
    return 0;
}
/*
x1=12  y1=20  x2=50  y2=40
x1=13  y1=21  x2=51  y2=41
 */
/*
“this”用于返回自身实例，在运算符重载中经常被使用。
 */
