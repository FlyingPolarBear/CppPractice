//类和对象的基本概念和用法(1)
#include <iostream>
using namespace std;

class CRectangle
{
public:
    int w, h;
    int Area()
    {
        return w * h;
    }
    int Perimeter()
    {
        return 2 * (w + h);
    }
    void Init(int w_, int h_)
    {
        w = w_;
        h = h_;
    }
};

int main()
{
    int w, h;
    CRectangle r;
    CRectangle &p = r;
    cin >> w >> h;
    r.Init(w, h);
    cout << "Area: " << r.Area() << endl
         << "Perimete: " << r.Perimeter() << endl
         << "Size: " << sizeof(CRectangle) << endl
         << "r.w: " << p.w << endl
         << "r.h: " << r.h << endl;
    return 0;
}