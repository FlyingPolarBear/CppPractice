#include <iostream>
using namespace std;

class son
{
    //不允许把构造函数设置为虚函数
public:
    virtual void f() = 0;
    //纯虚函数，包含纯虚函数的类叫抽象类
    //抽象类只能作为基类来派生新类使用，不能创建抽象类的对象
    //在构造函数和析构函数内部不能调用纯虚函数
    //只有实现了基类中所有纯虚函数，才能成为非抽象类
    void g() { this->f(); }
    virtual ~son() { cout << "bye from son" << endl; }
};

class grandson : public son
{
public:
    void f() { cout << "son::f()" << endl; }
    ~grandson() { cout << "bye from grandson" << endl; }
};

int main()
{
    son *pson;
    pson = new grandson();
    pson->g(); 
    delete pson;
    return 0;
}
