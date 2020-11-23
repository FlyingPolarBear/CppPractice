#include <iostream>
using namespace std;

//前置运算符作为一元运算符重载
//后置运算符作为二元运算符重载，要多写一个没用的参数

class cDemo
{
private:
    int n;

public:
    cDemo(int i = 0) : n(i) {}
    cDemo &operator++();
    cDemo operator++(int);
    operator int() { return n; }
    friend cDemo &operator--(cDemo &);
    friend cDemo operator--(cDemo &, int);
};

cDemo &cDemo::operator++()
{
    ++n;
    return *this;
}

cDemo cDemo::operator++(int k)
{
    cDemo tmp(*this);
    n++;
    return tmp;
}

cDemo &operator--(cDemo &d)
{
    d.n--;
    return d;
}
cDemo operator--(cDemo &d, int k)
{
    cDemo tmp(d);
    d.n--;
    return tmp;
}

int main()
{
    cDemo d(5);
    cout << (d++) << ",";
    cout << d << ",";
    cout << (++d) << ",";
    cout << d << endl;
    cout << (d--) << ",";
    cout << d << ",";
    cout << (--d) << ",";
    cout << d << endl;
    return 0;
}