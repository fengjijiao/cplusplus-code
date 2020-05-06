#include <cstdio>

using namespace std;

class Array {
public:
    Array(int len = 0);
    ~Array();
public:
    int length() const;
    void print() const;
public:
    int & operator[](int i);
    const int & operator[](int i) const;
private:
    int m_len;
    int *m_ptr;
};

Array::Array(int len) : m_len(len) {
    if (len == 0) {
        m_ptr = nullptr;
    } else {
        m_ptr = new int[len];
    }
}

Array::~Array() {
    delete[] m_ptr;
}

int Array::length() const {
    return m_len;
}

void Array::print() const {
    printf("Array[%d] = { ", m_len);
    for (int i=0; i<m_len; i++) {
        printf("%d, ", m_ptr[i]);
    }
    printf("\b\b }\n");
}

int & Array::operator[](int i) {
    return m_ptr[i];
}

const int & Array::operator[](int i) const {
    return m_ptr[i];
}

int main() {
    int len;
    printf("array_len: ");
    scanf("%d", &len);

    Array arr1(len);
    for (int i=0; i<arr1.length(); i++) {
        arr1[i] = i*5;
    }
    arr1.print();

    const Array arr2(len);
    printf("arr2[0] = %d\n", arr2[0]);
    return 0;
/*
该重载函数在类中的声明格式：返回值类型 & operator[](参数);，或者const 返回值类型 & operator[](参数) const;

使用第一种声明方式，[]不仅可以访问元素，还可以修改元素；
使用第二种声明方式，[]只能访问而不能修改元素；
在实际开发中，我们应该同时提供以上两种形式，这样做是为了适应 const 对象，因为通过 const 对象只能调用 const 成员函数，如果不提供第二种形式，那么将无法访问 const 对象的任何元素；
*/
