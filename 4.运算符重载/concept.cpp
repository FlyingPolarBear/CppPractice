#include <iostream>
using namespace std;

class Complex
{
public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    Complex operator-(const Complex &c);
};

// 重载为普通函数时，参数个数为运算符目数
Complex operator+(const Complex &a, const Complex &b)
{
    return Complex(a.real + b.real, a.imag + b.imag);
}

// 重载为成员函数时，参数个数为运算符目数减一
Complex Complex::operator-(const Complex &c)
{
    return Complex(real - c.real, imag - c.imag);
}

int main()
{
    Complex a(4, 4), b(1, 1), c;
    c = a + b; //c=operator+(a,b)
    cout << "c = " << c.real << "+" << c.imag << "i" << endl
         << "a-b = " << (a - b).real << "+" << (a - b).imag << "i" << endl;
    //a.operator-(b)
    return 0;
}