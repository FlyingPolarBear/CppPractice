#include<iostream>
using namespace std;
#include"string.h"
#include"account.h"

void Account::Deposit()
{
	cout<<"���������";
	float x;
	cin>>x;
	money+=x;
	Show();
}

void Account::WithDraw()
{
	cout<<"������ȡ���";
	float x;
	cin>>x;
	if(money<x) cout<<"�˻����㡣";
	else money-=x;
	Show();
}

void Account::Show()
{
	cout<<"�˺�"<<no<<"���˻����Ϊ��"<<money<<"Ԫ"<<endl;
}

Account::Account(float No,char *Name,float Money)
{
	no=No;strcpy(name,Name);money=Money;
}