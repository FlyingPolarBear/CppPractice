#include <iostream>
using namespace std;

class CArray
{
private:
    int size;
    int *ptr;

public:
    CArray(int s = 0); //s代表数组元素个数
    CArray(CArray &a);
    ~CArray();
    void push_back(int v);                    //在数组尾部添加一个元素v
    CArray &operator=(const CArray &a);       //用于数组对象间的赋值，深拷贝
    int length() { return size; }             //返回数组元素个数
    int &operator[](int i) { return ptr[i]; } //返回值为引用，否则不能写在等式左边
};

CArray::CArray(int s) : size(s)
{
    if (s == 0)
        ptr = NULL;
    else
        ptr = new int[s];
}

CArray::CArray(CArray &a)
{
    if (!a.ptr)
    {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}

CArray::~CArray()
{
    if (ptr)
        delete[] ptr;
}

CArray &CArray::operator=(const CArray &a)
{
    if (ptr == a.ptr)
        return *this;
    if (a.ptr == NULL)
    {
        if (ptr)
            delete[] ptr;
        size = 0;
        return *this;
    }
    if (size < a.size) //如果原有空间不足，才需要分配新的空间
    {
        if (ptr)
            delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}

void CArray::push_back(int v)
{
    if (ptr)
    {
        int *tmpPtr = new int[size + 1];
        memcpy(tmpPtr, ptr, sizeof(int) * size);
        delete[] ptr;
        ptr = tmpPtr;
    }
    else
        ptr = new int[1];
    ptr[size++] = v;
}

int main()
{
    CArray a;
    for (int i = 0; i < 5; i++)
        a.push_back(i); //用动态分配的内存来存放数组元素，需要应该指针成员变量
    CArray a2, a3;
    a2 = a; //要重载"="
    for (int i = 0; i < a.length(); i++)
        cout << a2[i] << " "; //要重载"[]"
    a2 = a3;
    for (int i = 0; i < a2.length(); i++)
        cout << a2[i] << " ";
    cout << endl;
    a[3] = 100;
    CArray a4(a); //自己写复制构造函数
    for (int i = 0; i < a4.length(); i++)
        cout << a4[i] << " ";
    return 0;
}