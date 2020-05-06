#include <cstdio>

using namespace std;

class complex {
public:
    complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag) {}
    void print() const;
    friend complex operator+(const complex &A, const complex &B);//运算符重载函数不是 complex 类的成员函数，但是却用到了 complex 类的 private 成员变量，所以必须在 complex 类中将该函数声明为友元函数；
private:
    double m_real;
    double m_imag;
};

void complex::print() const {
    printf("%g + %gi\n", m_real, m_imag);
}

complex operator+(const complex &A, const complex &B) {
    return complex(A.m_real + B.m_real, A.m_imag + B.m_imag);
}

int main() {
    complex A(1.24, 5.7), B(4, 3.14), C;
    C = A + B;
    C.print();
    return 0;
}
/*
5.24 + 8.84i
 */
/*
运算符重载函数不仅可以作为类的成员函数，还可以作为全局函数；在全局范围内重载+，实现复数的加法运算.
 */
/*
当执行C = A + B;语句时，编译器检测到+号两边都是 complex 对象，就会转换为类似这样的函数调用：C = operator+(A, B);
*/
