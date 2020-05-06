#include <iostream>

using namespace std;

class complex {
public:
    complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag) {}
    friend istream & operator>>(istream &in, complex &A);
    friend ostream & operator<<(ostream &out, complex &A);
private:
    double m_real;
    double m_imag;
};

istream & operator>>(istream &in, complex &A) {
    in >> A.m_real >> A.m_imag;
    return in;
}

ostream & operator<<(ostream &out, complex &A) {
    out << A.m_real << " + " << A.m_imag << "i";
    return out;
}

int main() {
    complex a, b;
    cin >> a >> b;
    cout << a << "\t" << b << endl;
    return 0;
}
