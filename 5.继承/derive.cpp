#include <iostream>
using namespace std;

class Skill
{
public:
    Skill(int n) {}
};

class Bug
{
private:
    int nLegs;
    int nColor;

public:
    int nType;
    Bug(int legs, int color) : nLegs(legs), nColor(color) {}
    void PrintBug() { cout << "Legs:" << nLegs << " "
                           << "Color:" << nColor << endl; };
};

class FlyBug : public Bug
{
    int nWings;
    Skill sk1, sk2;

public:
    //创建派生类的对象时，要先调用基类的构造函数，省略时自动调用基类的默认构造函数
    //先执行基类构造函数，再执行成员对象的构造函数，最后执行自己的构造函数
    FlyBug(int legs, int color, int wings) : Bug(legs, color), sk1(5), sk2(color), nWings(wings) {}
};

int main()
{
    FlyBug fb(2, 3, 4);
    fb.PrintBug();
    fb.nType = 1;
    return 0;
}