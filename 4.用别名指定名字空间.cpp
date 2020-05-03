#include <iostream>
using namespace std;
namespace na {
    namespace nb {
        namespace nc {
            int sum(int a, int b)
            {
                return a + b;
            }
        }
    }
}
namespace A = na::nb::nc;
//名字空间可以一层层嵌套，指定时也得一层层地指定，这样很不方便，一般用别名代替就方便多了。
int main ( )
{
    cout << na::nb::nc::sum(5, 11) << endl;
    cout << A::sum(6, 12) << endl;
    return 0;
}
/*
16
18
*/
