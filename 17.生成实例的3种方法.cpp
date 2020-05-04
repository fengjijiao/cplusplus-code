#include <iostream>
#include <string>
using namespace std;
int main ( )
{
    string strA("C++");  //直接调用构造函数生成实例
    cout << strA << "    " << strA.length() << endl;
    string strB;  //先调用构造函数生成空字符串实例
    strB = string("C++入门教程");  //再调用构造函数生成无名实例，然后复制给strB实例，无名实例立即销毁
    cout << strB << "    " << strB.length() << endl;  //这和上面①的方法的结果相同
    string *strC;  //先定义一个指针，尚未分配空间
    //动态调用构造函数生成实例后，再将实例地址赋给指针变量
    strC = new string("http://see.xidian.edu.cn/cpp/biancheng/cpp/jichu/");
    cout << *strC << "    " << strC->length() << endl;
    delete strC;              //千万不要忘记释放
    return 0;
}
/*
了解生成实例的三种方法的细微区别是很重要的：
申明为变量；
从无名对象复制；
申明为指针并动态生成。

注意：指针的成员用“->”，而不用“.”。
*/
