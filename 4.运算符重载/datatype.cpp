#include <iostream>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    operator double() { return real; } //返回值不写
};

int main()
{
    Complex c(1.2, 3.4);
    cout << (double)c << endl;
    double d = 2 + c; //等价于double n=2+c.operator double()
    cout << d << endl;
    return 0;
}
