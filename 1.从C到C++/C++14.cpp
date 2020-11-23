//内联函数、重载函数和函数缺省值
#include <iostream>
using namespace std;

inline int Max(float a, float b = 10)
{
    if (a > b)
        return a;
    return b;
}

inline int Max(int a, int b = 10)
{
    if (a > b)
        return a;
    return b;
}

// inline int Max(int a, int b, int c)
// {
//     if (a > b && a > c)
//         return a;
//     else if (b > c)
//         return b;
//     return c;
// }

int main()
{
    float a = 6, b = 7, c = 5;
    cout << Max(a) << endl;
    return 0;
}
