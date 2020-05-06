#include <iostream>
#include <string>
using namespace std;
class classA {
    static int sx;
    static string sstr;
public:
    static int sy;
    void set(int x, string s) {
        sx = x;
        sstr = s;
    }
    void print() {
        cout << "  x = " << sx ;
        cout << "  y = " << sy ;
        cout << "  s = " << sstr << endl;
    }
};
//important,static均需要声明
//下面的申明是必须的，这样不会改变访问权限(public,private)
int classA::sx;
string classA::sstr;
int classA::sy;
int main ( )
{
    classA ca1, ca2;
    cout << "ca1: ", ca1.print();   //实例1的初始值
    cout << "ca2: ", ca2.print();   //实例2的初始值
    ca1.set(25, "C");    //设定实例1，实例2 也会改变
    ca1.sy = 100;       //公有静态成员可以通过实例来设定
    cout << "ca1: ", ca1.print();   //实例1的设定值
    cout << "ca2: ", ca2.print();   //实例2的设定值
    ca2.set(80, "C++");    //设定实例2，实例1 也会改变
    classA::sy = 125;   //公有静态成员也可以不通过实例来设定
    cout << "ca1: ", ca1.print();   //实例1的设定值
    cout << "ca2: ", ca2.print();   //实例2的设定值
    return 0;
}
/*
ca1:   x = 0  y = 0  s =
ca2:   x = 0  y = 0  s =
ca1:   x = 25  y = 100  s = C
ca2:   x = 25  y = 100  s = C
ca1:   x = 80  y = 125  s = C++
ca2:   x = 80  y = 125  s = C++
 */
