#include <iostream>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}
    void Print() { cout << real << "+" << imag << "i" << endl; }
    Complex operator+(double r) { return Complex(real + r, imag); }
    friend Complex operator+(double r, const Complex &c) { return Complex(c.real + r, c.imag); }
};

int main()
{
    Complex c(2, 3);
    c = c + 5;
    c = 5 + c;
    c.Print();
    return 0;
}