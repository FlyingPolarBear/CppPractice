class Account
{
private:
	float no; //�˺�
	char name[10]; //�˻���
	float money; //�����
public:
	void Deposit(); //���
	void WithDraw(); //ȡ��
	void Show(); //��ʾ���
	Account(float No,char Name[10],float Money);
};