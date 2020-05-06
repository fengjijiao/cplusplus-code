#include <iostream>
#include <cstdio>

using namespace std;

class stopwatch {
public:
    stopwatch() : m_min(0), m_sec(0) {}
public:
    void setzero() { m_min = m_sec = 0; }
    stopwatch run();
    stopwatch operator++(); // ++i 前置形式
    stopwatch operator++(int); // i++ 后置形式
    friend ostream & operator<<(ostream &out, const stopwatch &s);
private:
    int m_min;
    int m_sec;
};

stopwatch stopwatch::run() {
    m_sec++;
    if (m_sec == 60) {
        m_min++;
        m_sec = 0;
    }
    return *this;
}

stopwatch stopwatch::operator++() {
    return run();
}

stopwatch stopwatch::operator++(int) {
    stopwatch s = *this;
    run();
    return s;
}

ostream & operator<<(ostream &out, const stopwatch &s) {
    out << s.m_min << ":" << s.m_sec << endl;
    return out;
}

int main() {
    stopwatch s1, s2;

    s1 = s2++;
    cout << s1 << s2;

    s1.setzero(); s2.setzero();
    s1 = ++s2;
    cout << s1 << s2;

    return 0;
}
/*
自增++和自减--都是一元运算符，它的前置形式和后置形式都可以被重载.
*/
