#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class CShape
{
public:
    virtual double Area() = 0;
    virtual void PrintInfo() = 0;
};

class CRectangle : public CShape
{
public:
    int w, h;
    // 派生类中和基类同名同参数表的函数，不加virtual也自动成为虚函数
    double Area() { return w * h; }
    void PrintInfo() { cout << "Rectangle:" << Area() << endl; }
};

class CCircle : public CShape
{
public:
    int r;
    double Area() { return 3.14 * r * r; }
    void PrintInfo() { cout << "Circle:" << Area() << endl; }
};

class CTritangle : public CShape
{
public:
    int a, b, c;
    double Area();
    void PrintInfo() { cout << "Tritangle:" << Area() << endl; }
};

double CTritangle::Area()
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

//用基类指针数组存放指向各种派生类对象的指针，
//然后遍历该数组，就能对派生类对象做各种操作，这是很常用的做法
CShape *pShapes[100];
int MyCompare(const void *s1, const void *s2);

int main()
{
    int n;
    CRectangle *pr;
    CCircle *pc;
    CTritangle *pt;
    cout << "Input numbers: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cout << "Input the type(R/C/T): ";
        cin >> c;
        switch (c)
        {
        case 'R':
            pr = new CRectangle();
            cin >> pr->w >> pr->h;
            pShapes[i] = pr;
            break;
        case 'C':
            pc = new CCircle();
            cin >> pc->r;
            pShapes[i] = pc;
            break;
        case 'T':
            pt = new CTritangle();
            cin >> pt->a >> pt->b >> pt->c;
            pShapes[i] = pt;
            break;
        }
    }
    qsort(pShapes, n, sizeof(CShape *), MyCompare);
    for (int i = 0; i < n; i++)
        pShapes[i]->PrintInfo();
    return 0;
}

int MyCompare(const void *s1, const void *s2)
{
    CShape **p1 = (CShape **)s1, **p2 = (CShape **)s2; //不可写*s1来取得s1指向的内容
    return (*p1)->Area() - (*p2)->Area();
}

//在构造函数和析构函数里面调用虚函数，不是多态