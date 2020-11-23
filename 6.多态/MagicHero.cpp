#include <iostream>
using namespace std;

class CCreature
{
protected:
    int m_nLifeValue, m_nPower;

public:
    virtual void Attack(CCreature *pCreature);
    virtual void Hurted(int nPower);
    virtual void FightBack(CCreature *pCreature);
};

class CDragon : public CCreature
{
public:
    virtual void Attack(CCreature *pCreature);
    virtual void Hurted(int nPower) { m_nLifeValue -= nPower; }
    virtual void FightBack(CCreature *pCreature);
};

void CDragon::Attack(CCreature *p)
{
    p->Hurted(m_nPower);
    p->FightBack(this);
}

void CDragon::FightBack(CCreature *p) { p->Hurted(m_nPower / 2); }

int main()
{
    return 0;
}