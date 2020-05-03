/*
许多教程在讲解参数引用时都喜欢选择交换两参数内容的swap(int &x, int &y)函数作例子，这的确很容易说明清楚，但并不能说这种用法优于指针作参数。
*/
#include <iostream>
using namespace std;
                                                //|右边为指针作参数的代码，仅作比较用。
void swap(int &x, int &y);                      //|void swap(int *x, int *y);
                                                //|
int main ( )                                    //|
{                                               //|
    int i = 12;                                 //|
    int j = 25;                                 //|
    cout << "i=" << i << "   j=" << j << endl;  //|
                                                //|
    swap(i, j);                                 //|swap(&i, &j);
    cout << "i=" << i << "   j=" << j << endl;  //|
                                                //|
    return 0;                                   //|
}                                               //|
                                                //|
void swap(int &x, int &y)                       //|void swap(int *x, int *y)
{                                               //|{
    int t;                                      //|    int t;
                                                //|
    t = x;                                      //|    t = *x;
    x = y;                                      //|    *x = *y;
    y = t;                                      //|    *y = *x;
}                                               //|}
/*
i=12    j=25
i=25    j=12
*/
