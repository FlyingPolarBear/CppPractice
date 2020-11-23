#include <iostream>
using namespace std;

class CMaster;

class CDog
{
public:
    CMaster *pm;
};

class CMaster
{
public:
    CDog *dogs[10];
};

int main()
{
    CMaster m;
    CDog d1, d2;
    d1.pm = &m;
    d2.pm = &m;
    m.dogs[0]={&d1};
    m.dogs[1]={&d2};
    return 0;
}