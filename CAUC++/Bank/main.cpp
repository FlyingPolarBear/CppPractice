#include<iostream>
using namespace std;
#include<string.h>
#include"account.h"

int main()
{
	cout<<"�����뿪����Ϣ���˺� �˻��� ������";
	float x;char str[10];float y;
	cin>>x>>str>>y;

	Account obj(x,str,y);

	int choice;
	while(1)
	{
		cout<<"******��ӭʹ�ñ�ϵͳ******"<<endl;
		cout<<"1-���\n2-ȡ��\n3-��ѯ���\n0-�˳�\n��ѡ��";
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