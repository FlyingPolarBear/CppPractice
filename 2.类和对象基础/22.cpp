#include <iostream>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex(double r, double i);
    Complex(Complex c1, Complex c2);
    void Set(double r, double i);
};

class Test
{
public:
    Test(int n) { cout << "Test(1) "
                       << " n = " << n << endl; }
    Test(int n, int m) { cout << "Test(2) "
                              << " n = " << n << " m = " << m << endl; }
    Test() { cout << "Test(3)" << endl; }
    void Out() { cout << "hello" << endl; }
};

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
    cout << r << " " << i << endl;
}

Complex::Complex(Complex c1, Complex c2)
{
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
}

void Complex::Set(double r, double i)
{
    real = r;
    imag = i;
    cout << r << " " << i << endl;
}

int main()
{
    // double a = 2, b = 3;
    // Complex c(4, 5);
    // c.Set(a, b);
    // Test array1[3] = {1, Test(1, 2)};
    // Test array2[3] = {Test(2, 3), Test(1, 2), 1};
    // Test *pArray[3] = {new Test(4), new Test(1, 2)};
    Test a = 1;
    Test b1 = a; // 复制构造函数
    Test b2(a);  // 复制构造函数
    b1.Out();
    return 0;
}