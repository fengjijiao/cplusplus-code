#include <iostream>
#include <string>
using namespace std;
class CBase1 {
    string name;
protected:
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
protected:
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
    void show() {
        cout << "id: " << id << endl;
        cout << "age: " << age << endl;
        CBase1::show();
        CBase2::show();
        cout << "bas1: " << CBase1::id << endl;  //调用CBase1的成员变量
        cout << "bas2: " << CBase2::id << endl;  //调用CBase2的成员变量
    }
};
int main ( )
{
    CDerive d("C++", 3, "8503026", 5000);
    d.show();
    return 0;
}
/*
id: DERIVE-8503026
age: 3
name: C++
id: base1-8503026
salary: 5000
id: base2-8503026
bas1: base1-8503026
bas2: base2-8503026
 */
