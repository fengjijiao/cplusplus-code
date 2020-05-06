#include <cstdio>

using namespace std;

class complex {
public:
    complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag) {}
    void print() const;
    complex operator+(const complex &A) const;
private:
    double m_real;
    double m_imag;
};

void complex::print() const {
    printf("%g + %gi\n", m_real, m_imag);
}

complex complex::operator+(const complex &A) const {
    return complex(m_real + A.m_real, m_imag + A.m_imag);
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
