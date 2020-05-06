#include <cstdio>

using namespace std;

class complex {
public:
    complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag) {}
    void print() const;
    friend complex operator+(const complex &A, const complex &B);
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
运算符重载函数不仅可以作为类的成员函数，还可以作为全局函数；更改上面的代码，在全局范围内重载+，实现复数的加法运算.
 */
