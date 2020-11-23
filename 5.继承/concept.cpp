#include <iostream>
#include <string>
using namespace std;

class CStudent
{
private:
    string name;
    string id;
    int age;
    char gender;

public:
    void PrintInfo() { cout << "Name:" << name << endl
                            << "ID:" << id << endl
                            << "Age:" << age << endl
                            << "Gender:" << gender << endl; }
    void SetInfo(const string &name_, const string &id_, int age_, char gender_)
    {
        name = name_;
        id = id_;
        age = age_;
        gender = gender_;
    };
    string GetName() { return name; }
};

class CUndergraduateStudent : public CStudent
{
private:
    string department;

public:
    void QualifiedForBaoyan() { cout << "has qualified for baoyan!" << endl; }
    void PrintInfo() //覆盖
    {
        CStudent::PrintInfo();
        cout << "Department:" << department << endl;
    }
    void SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_)
    {
        CStudent::SetInfo(name_, id_, age_, gender_);
        department = department_;
    }
};

int main()
{
    CUndergraduateStudent s2;
    s2.SetInfo("Harry Potter", "118829212", 19, 'M', "Computer Science");
    cout << s2.GetName() << " ";
    s2.QualifiedForBaoyan();
    s2.PrintInfo();
    return 0;
}