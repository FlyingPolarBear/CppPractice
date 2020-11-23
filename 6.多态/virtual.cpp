#include <iostream>
using namespace std;

class CBase
{
public:
    virtual void SomeVirtualFunction() { cout << "CBase::Print" << endl; }
};

class CDrived : public CBase
{
public:
    virtual void SomeVirtualFunction() { cout << "CDrived::Print" << endl; }
};

int main()
{
    CDrived ODerived;
    //多态一：调用哪个虚函数取决于p指向哪种类型的对象
    CBase *p = &ODerived;
    p->SomeVirtualFunction();

    //多态二：调用哪个虚函数取决于r引用哪种类型的对象
    CBase &r = ODerived;
    r.SomeVirtualFunction();
    return 0;
}