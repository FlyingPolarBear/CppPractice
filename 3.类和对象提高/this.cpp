#include <iostream>
using namespace std;

class Complex
{
public:
    double real, imag;
    void Print() { cout << real << "+" << imag << "i" << endl; }
    Complex(double r, double i) : real(r), imag(i) {}
    Complex AddOne()
    {
        this->real++;  //equal to "real++;""
        this->Print(); //equal to "Print();"
        return *this;
    }
};

int main()
{
    Complex c(1, 1);
    Complex a = c;
    a = c.AddOne();
    a.AddOne();
    return 0;
}