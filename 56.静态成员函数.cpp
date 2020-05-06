#include <iostream>
using namespace std;
class Integer {
public:
    const int a = 10;
    static int atoi(const char *s) {
        return ::atoi(s);//:: = std ::
    }
    static float atof(const char *s) {
        return ::atof(s);
    }
};
int main ( )
{
    Integer *integer = new Integer();
    cout << integer->a << endl;
    //cout << Integer::a << endl; Integer::a不是静态的无法通过类名直接访问
    int x = Integer::atoi("322");
    float y = Integer::atof("3.14");
    cout << "x = " << x << "  y = " << y << endl;
    return 0;
}
/*
10
 x = 322  y = 3.14
 */
/*
按Java的经验，静态成员函数一般在公共程序中用的比较多。这样的程序与类自身关系不大，只是归类性质放在某个类中。还有一些与类转换或交换但不需要实例时使用的情况。
 */
