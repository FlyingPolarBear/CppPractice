#include <iostream>
using namespace std;

class CCar;
class CDriver
{
public:
    void ModifyCar1(CCar *pCar);
    void ModifyCar2(CCar *pCar);
};

class CCar
{
private:
    int price;
    friend int MostExpensiveCar(CCar cars[], int total); //声明友元
    friend void CDriver::ModifyCar1(CCar *pCar);         //声明友元
    friend class CDriver;                                //声明友元类
};

void CDriver::ModifyCar1(CCar *pCar)
{
    pCar->price += 1000;
}

void CDriver::ModifyCar2(CCar *pCar)
{
    pCar->price += 2000;
}

int MostExpensiveCar(CCar cars[], int total)
{
    int tmpMax = -1;
    for (int i = 0; i < total; i++)
        if (cars[i].price > tmpMax)
            tmpMax = cars[i].price;
    return tmpMax;
}

int main()
{
    return 0;
}