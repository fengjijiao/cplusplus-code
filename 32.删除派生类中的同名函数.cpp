#include <iostream>
#include <string>
using namespace std;
class CBase1 {
    string name;
    string id;
public:
    CBase1(string s1, string s2) : name(s1), id("base1-"+s2) { }
    void show() {
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
    }
};
class CBase2 {
    int salary;
    string id;
public:
    CBase2(int y, string s2) : salary(y), id("base2-"+s2) { }
    void show() {
        cout << "salary: " << salary << endl;
        cout << "id: " << id << endl;
    }
};
class CDerive : public CBase1, public CBase2 {
    string id;
    int age;
public:
    CDerive(string s1, int a, string s2, int y)
            : age(a), id("DERIVE-"+s2), CBase1(s1, s2), CBase2(y, s2) { }
};
int main ( )
{
    CDerive d("C++", 3, "8503026", 5000);
    //d.show();    //编译出错，不知从哪个基类继承。
    d.CBase1::show();
    d.CBase2::show();
    return 0;
}
/*
name: C++
id: base1-8503026
salary: 5000
id: base2-8503026
 */
/*
如果修改2个基类的show()函数的参数，在派生类或外部也一样不能直接调用，必须加上范围。下面，我们将派生类中的同名函数show()删除，是否会出错呢？
 */
