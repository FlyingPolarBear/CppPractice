#include <iostream>
using namespace std;

class Sample
{
private:
    int n;

public:
    int value;
    int GetValue() const;
    int GetValue();
    void func();
    Sample() { n = 1; }
};

int Sample::GetValue() const
{
    return n;
}

int Sample::GetValue()
{
    return 2 * n;
}

int main()
{
    const Sample o1;
    Sample o2;
    cout << o1.GetValue() << endl
         << o2.GetValue() << endl;
    return 0;
}