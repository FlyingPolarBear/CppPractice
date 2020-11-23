//动态内存分配
#include <iostream>
using namespace std;

int main()
{
    int *p1 = new int;
    *p1 = 5;
    delete p1;

    int *p2 = new int[20];
    p2[0] = 20;
    delete[] p2;

    return 0;
}
