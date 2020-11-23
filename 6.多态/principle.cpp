#include <iostream>
using namespace std;

class Base
{
public:
    int i;
    virtual void Print() { cout << "Base::Print" << endl; }
};

class Derived : public Base
{
public:
    int n;
    virtual void Print() { cout << "Derived::Print" << endl; }
};

int main()
{
    Derived d;
    //每一个多态对象都要多4个字节存放虚函数表的地址，每次执行时需要查找虚函数表
    cout << sizeof(Base) << "," << sizeof(Derived);
    return 0;
}
