#include <iostream>
using namespace std;

class CRectangle
{
private:
    int w, h;
    static int nTotalArea; //静态成员变量被所有对象共享，sizeof不计算
    static int nTotalNumber;

public:
    CRectangle(int w_, int h_);
    CRectangle(CRectangle &r);
    ~CRectangle();
    static void PrintTotal();
    //在静态成员函数中，不能访问非静态成员变量，也不能调用非静态成员函数
};

//静态成员变量需要另外定义
int CRectangle::nTotalNumber = 0;
int CRectangle::nTotalArea = 0;

CRectangle::CRectangle(int w_, int h_)
{
    w = w_;
    h = h_;
    nTotalNumber++;
    nTotalArea += w * h;
}

CRectangle::~CRectangle()
{
    nTotalNumber--;
    nTotalArea -= w * h;
}

CRectangle::CRectangle(CRectangle &r)
{
    w = r.w;
    h = r.h;
    nTotalNumber++;
    nTotalArea += w * h;
}

void CRectangle::PrintTotal()
{
    cout << "------------------------" << endl
         << "TotalNumber: " << nTotalNumber << endl
         << "TotalArea: " << nTotalArea << endl;
}

int main()
{
    CRectangle c1(2, 3);
    CRectangle c2(4, 5);
    CRectangle *c3 = new CRectangle(8,9);
    c2.PrintTotal();
    delete c3;
    c2.PrintTotal();
    return 0;
}