#include <iostream>
#include <string>
using namespace std;
class CBase1 {
    string name;
public:
    CBase1(string s) : name(s) {
        cout << "BASE1: " << name << endl;
    }
    ~CBase1() {
        cout << "~BASE1" << endl;
    }
};
class CBase2 {
    int age;
public:
    CBase2(int a) : age(a) {
        cout << "BASE2: " << age << endl;
    }
    ~CBase2() {
        cout << "~BASE2" << endl;
    }
};
class CDerive : public CBase1, public CBase2 {
    string id;
public:
    CDerive(string s1, int a, string s2) : CBase1(s1), CBase2(a), id(s2) {
        cout << "DERIVE: " << id << endl;
    }
    ~CDerive() {
        cout << "~DERIVE" << endl;
    }
};
int main ( )
{
    CDerive d("小雅", 27, "8503026");
    return 0;
}
/*
BASE1: 小雅
BASE2: 27
DERIVE: 8503026
~DERIVE
~BASE2
~BASE1
 */
/*
多重继承时参数的传递方法和上面一样，要注意的是两个基类的顺序。决定2个基类的顺序是知27行。将27行的CBase1和CBase2的顺序交换一下，其结果中BASE1和BASE2的顺序也随之改变，与第30行无关。
 */
