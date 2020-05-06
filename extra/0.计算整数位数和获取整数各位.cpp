#include <iostream>
#include <cstring>
int getDigits(int g) {//合并正负计算位数
    int i=0, c, y;
    while(true) {
        c = g/10;
        y = g%10;
        if(c != 0 || y != 0) {
            i++;
        }else {
            break;
        }
        g = c;
    }
    return i;
}
int* getPosDigits(int g, int len) {//合并正负计算位数
    if(g < 0) {//负数会增加第一位为-1
        len++;
    }
    int * arr;
    int c, y, j = len - 1;
    arr = new int[len];//采用动态内存分配可以在函数外部调用生成的指针，否则在函数执行后内容会被自动释放
    memset(arr, 0 ,len);//全置0
    //std::cout << arr[1] << std::endl;
    if(g < 0) {//负数会增加第一位为-1
        arr[0] = -1;
    }
    while(j >= 0) {
        c = g/10;
        y = g%10;
        if(c != 0 || y != 0) {
            //std::cout << j << "   " << y << std::endl;
            arr[j] = abs(y);
        }else {
            break;
        }
        g = c;
        j--;
    }
    return arr;
}
