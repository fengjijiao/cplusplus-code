/*
//单目运算符
成员函数：      返回值类型  operator  运算符  () ;
普通函数：      返回值类型  operator  运算符  (对象的类型) ;

//双目运算符
成员函数：      返回值类型  operator  运算符  (对象的类型) ;
普通函数：      返回值类型  operator  运算符  (对象的类型1, 对象的类型2) ;

//函数调用
成员函数：      返回值类型  operator  (任意的参数列) ;

//数组元素
成员函数：      返回值类型  operator[]  (参数类型) ;

//增1/减1运算符
成员函数：      返回值类型  operator  运算符  (int) ;
普通函数：      返回值类型  operator  运算符  (对象的类型, int) ;
*/
#include <iostream>
#include <string>
using namespace std;
class stuff {
    string name;
    int age;
    int grade;
public:
    stuff(string n, int a, int g):name(n),age(a),grade(g)//将构造函数的参数映射到成员变量
    {
        cout << name << "---" << age << endl;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    int getGrade() {
        return grade;
    }
    void operator +(int x);       //运算符重载的定义
    void operator +(string s);    //运算符重载的定义
};
void stuff::operator +(int x)       //运算符重载的实装
{
    age = age + x;
    grade = grade + x;
}
void stuff::operator +(string s)    //运算符重载的实装
{
    name = name + s;
}
int main ( )
{
    stuff st2("I`am Jak", 3, 3);
    st2 + 2; //+运算
    st2 + ".C++ 入门教程";    //+运算
    cout << st2.getName() << st2.getAge() << st2.getGrade() << endl;
    return 0;
}
//注意是将整个实例化对象作为操作数来进行运算。
/*
I`am Jak---3
I`am Jak.C++ 入门教程5
*/
