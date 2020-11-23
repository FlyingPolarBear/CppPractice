#include<iostream>
using namespace std;
#include<string.h>
#include"account.h"

int main()
{
	cout<<"请输入开户信息（账号 账户名 存款金额）：";
	float x;char str[10];float y;
	cin>>x>>str>>y;

	Account obj(x,str,y);

	int choice;
	while(1)
	{
		cout<<"******欢迎使用本系统******"<<endl;
		cout<<"1-存款\n2-取款\n3-查询余额\n0-退出\n请选择：";
		cin>>choice;
		switch(choice){
			case 0: return 0;
			case 1: obj.Deposit();break;
			case 2: obj.WithDraw();break;
			case 3: obj.Show();
		}
	}
	return 0;
}