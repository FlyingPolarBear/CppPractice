class Account
{
private:
	float no; //账号
	char name[10]; //账户名
	float money; //存款金额
public:
	void Deposit(); //存款
	void WithDraw(); //取款
	void Show(); //显示余额
	Account(float No,char Name[10],float Money);
};