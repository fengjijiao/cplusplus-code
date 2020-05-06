#include <iostream>
#include <string>
using namespace std;
class ca;    //事先申明ca类，确保cb类的定义不出错
class cb {    //在ca类之前定义cb类，确保在ca类里申明cb的test()作友元时不出错
public:
    void test(ca& a);    //由于ca类事先申明，这儿不出错
};
class ca {
    string id;
    void setId(string s) {
        id = s;
    }
protected:
    string name;
    void setName(string s) {
        name = s;
    }
public:
    void print() {
        cout << id << "  " << name << "  " << endl;
    }
    friend void cb::test(ca& a);    //申明cb类的test()函数作友元，允许它访问私有保护成员
};
void cb::test(ca& a) {  //作友元的成员函数的实装必须在ca类的后面，否则ca类的成员就未定义了。
    a.id = "123";        //这是ca类的私有成员
    a.setName("abc");    //这是ca类的保护成员
}
int main ( )
{
    ca a;
    cb b;
    b.test(a);
    a.print();
    return 0;
}
/*
123  abc  
 */
/*
别的类的成员函数作友元，也就是说这2个类相互调用，这样无论谁定义在前在后，编译时都有冲突。要解决这个问题，只要将类的申明、定义、实装分开就可以了。
 */
