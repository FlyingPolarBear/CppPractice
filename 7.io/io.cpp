#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);   //将标准输出重定向到input.txt文件
    freopen("output.txt", "w", stdout); //将标准输出重定向到output.txt文件
    double x, y;
    cin >> x >> y;
    if (y == 0)
        cerr << "input error" << endl; //除数为0则在屏幕上显示错误信息
    else
        cout << "x/y = " << x / y; //输出结果到output.txt，不在屏幕上显示
    return 0;
}
