//引用
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int n3 = 4;
int &SetValue() { return n3; }

int main()
{
    int n1 = 1, n2 = 2;
    swap(n1, n2);
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;

    SetValue() = 40;
    cout << "n3 = " << n3 << endl;

    int r = 100;
    const int &n4 = r; //常引用
    r = 300;
    cout << "n4 = " << n4 << endl;
    return 0;
}