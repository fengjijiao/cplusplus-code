#include <iostream>
#include <string>
using namespace std;
class stuff {
    string name;
    int age;
public:
    stuff() {        //这是写法一
        cout << name << "---" << age << endl;
        name = "空";
        age = 0;
        cout << name << "---" << age << endl;
    }
    stuff(string n, int a):name(n),age(a)     //这是写法二
    {
        cout << name << "---" << age << endl;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
};
int main ( )
{
    stuff st2;
    stuff st1("C++", 3);
    return 0;
}
/*
----12816
空---0
C++---3
*/
