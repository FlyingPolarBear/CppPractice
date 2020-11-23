#include <iostream>
using namespace std;
int main()
{
    int n = 1, m = 2;
    cout << "n: " << n << " m: " << m << endl;
    swap(n, m);
    cout << "n: " << n << " m: " << m << endl;
    double f = 2.4, g = 6.5;
    cout << "f: " << f << " g: " << g << endl;
    swap(f,g);
    cout << "f: " << f << " g: " << g << endl;
}

template <class T>
void swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}
