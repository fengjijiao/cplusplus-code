#include <iostream>
#include <cmath>

using namespace std;

class complex {
public:
    complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag) {}
    friend ostream & operator<<(ostream &out, complex &A);
    friend complex operator+(const complex &A, const complex &B);
    friend complex operator-(const complex &A, const complex &B);
    friend complex operator*(const complex &A, const complex &B);
    friend complex operator/(const complex &A, const complex &B);
    friend bool operator==(const complex &A, const complex &B);
    friend bool operator!=(const complex &A, const complex &B);
    void operator+=(const complex &A);
    void operator-=(const complex &A);
    void operator*=(const complex &A);
    void operator/=(const complex &A);
private:
    double m_real;
    double m_imag;
};

ostream & operator<<(ostream &out, complex &A) {
    out << A.m_real << " + " << A.m_imag << "i";
    return out;
}

complex operator+(const complex &A, const complex &B) {
    return complex(A.m_real + B.m_real, A.m_imag + B.m_imag);
}

complex operator-(const complex &A, const complex &B) {
    return complex(A.m_real - B.m_real, A.m_imag - B.m_imag);
}

complex operator*(const complex &A, const complex &B) {
    return complex(A.m_real*B.m_real - A.m_imag*B.m_imag, A.m_imag*B.m_real + A.m_real*B.m_imag);
}

complex operator/(const complex &A, const complex &B) {
    return complex((A.m_real*B.m_real + A.m_imag*B.m_imag)/(pow(B.m_real, 2) + pow(B.m_imag, 2)), (A.m_imag*B.m_real - A.m_real*B.m_imag)/(pow(B.m_real, 2) + pow(B.m_imag, 2)));
}

bool operator==(const complex &A, const complex &B) {
    if (A.m_real == B.m_real && A.m_imag == B.m_imag) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const complex &A, const complex &B) {
    if (A.m_real != B.m_real || A.m_imag != B.m_imag) {
        return true;
    } else {
        return false;
    }
}

void complex::operator+=(const complex &A) {
    m_real += A.m_real;
    m_imag += A.m_imag;
}

void complex::operator-=(const complex &A) {
    m_real -= A.m_real;
    m_imag -= A.m_imag;
}

void complex::operator*=(const complex &A) {
    m_real = m_real * A.m_real - m_imag * A.m_imag;
    m_imag = m_imag * A.m_real + m_real * A.m_imag;
}

void complex::operator/=(const complex &A) {
    m_real = (m_real*A.m_real + m_imag*A.m_imag) / (pow(A.m_real, 2) + pow(A.m_imag, 2));
    m_imag = (m_imag*A.m_real - m_real*A.m_imag) / (pow(A.m_real, 2) + pow(A.m_imag, 2));
}

int main() {
    complex c1(10, 20), c2(3, 5), c3;

    c3 = c1 + c2;
    cout << c3 << endl;

    c3 = c1 - c2;
    cout << c3 << endl;

    c3 = c1 * c2;
    cout << c3 << endl;

    c3 = c1 / c2;
    cout << c3 << endl;

    c3 += c1;
    cout << c3 << endl;

    c3 -= c2;
    cout << c3 << endl;

    c3 *= c1;
    cout << c3 << endl;

    c3 /= c2;
    cout << c3 << endl;

    if (c1 == c2) {
        cout << "c1 == c2" << endl;
    }

    if (c1 != c2) {
        cout << "c1 != c2" << endl;
    }
    return 0;
}
