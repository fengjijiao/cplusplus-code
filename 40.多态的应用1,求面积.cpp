#include <iostream>
using namespace std;
class Shape {
    double dim1, dim2;
public:
    void setData(double m, double n) {
        dim1 = m;
        dim2 = n;
    }
    void getData(double &m, double &n) {
        m = dim1;
        n = dim2;
    }
    virtual double getArea() = 0;// = 0 was important
};
class Rectange : public Shape {
public:
    double getArea() {
        double dim1, dim2;
        getData(dim1, dim2);
        return dim1*dim2;
    }
};
class Triange : public Shape {
public:
    double getArea() {
        double dim1, dim2;
        getData(dim1, dim2);
        return dim1*dim2/2;
    }
};
int main() {
    Shape *s;
    Rectange r;
    Triange t;
    r.setData(3, 4);
    t.setData(5, 6);
    cout << "Rectange, Area:" << r.getArea() << endl;
    cout << "Triange, Area:" << t.getArea() << endl;
    s = &r;
    cout << "Rectange, Area:" << s -> getArea() << endl;
    s= &t;
    cout << "Triange, Area:" << s -> getArea() << endl;
    return 0;
}
/*
Rectange, Area:12
Triange, Area:15
Rectange, Area:12
Triange, Area:15
 */
