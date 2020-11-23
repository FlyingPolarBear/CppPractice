#include<iostream>
using namespace std;
#include"string.h"
#include"account.h"

void Account::Deposit()
{
	cout<<"请输入存款金额：";
	float x;
	cin>>x;
	money+=x;
	Show();
}

void Account::WithDraw()
{
	cout<<"请输入取款金额：";
	float x;
	cin>>x;
	if(money<x) cout<<"账户余额不足。";
	else money-=x;
	Show();
}

void Account::Show()
{
	cout<<"账号"<<no<<"的账户余额为："<<money<<"元"<<endl;
}

Account::Account(float No,char *Name,float Money)
{
	no=No;strcpy(name,Name);money=Money;
}