#include <iostream>
#include <string.h>
using namespace std;

class String
{
private:
    char *str;

public:
    String() : str(new char[1]) { str[0] = 0; }
    const char *c_str() { return str; };
    String &operator=(const char *s);
    String &operator=(const String &s);
    String(String &s)
    {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    ~String() { delete[] str; }
};

String &String::operator=(const char *s)
{
    //重载"="使得obj="hello"能够成立
    delete[] str;
    str = new char[strlen(s) + 10];
    strcpy(str, s);
    return *this;
}

String &String::operator=(const String &s)
{
    if (this == &s)
        return *this;
    delete[] str;
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
    return *this;
}

int main()
{
    String s1, s2;
    s1 = "Good Luck,"; //等价于s.operator=("Good Luck,");
    cout << s1.c_str() << endl;
    //String s2="hello!"; //这条语句必须注释掉
    s2 = "Shenzhou 8!"; //等价于s.operator=("Shenzhou 8!");
    cout << s2.c_str() << endl;
    String s3;
    s3 = s2 = s2; //此句如果不修改第二个重载则会出错
    cout << s3.c_str() << endl;
    return 0;
}