#include <iostream>
#include <cstdlib>
using namespace std;
class classA {
    int x;
public:
    classA(int x) { this->x = x; }
    classA(char *x) { this->x = atoi(x); }
    int getX() { return x; }
};
int main ( )
{
    classA ca(5);    //正常调用构造函数
    cout << "x = " << ca.getX() << endl;
    ca = 100;        //缺省调用classA(100)
    cout << "x = " << ca.getX() << endl;
    ca = "255";      //缺省调用classA("255")
    cout << "x = " << ca.getX() << endl;
    return 0;
}
/*
x = 5
x = 100
x = 255
*/
