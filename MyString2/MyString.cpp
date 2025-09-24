#include "MyString.h"
#include <cstring>

int MyString::objectCount = 0;

MyString::MyString()
{
    length = 80;
    str = new char[length + 1] {};
    objectCount++;
}

MyString::MyString(int size)
{
    length = size;
    str = new char[length + 1] {};
    objectCount++;
}

MyString::MyString(const char* st)
{
    length = strlen(st);
    str = new char[length + 1];
    strcpy_s(str, length + 1, st);
    objectCount++;
}

MyString::MyString(const MyString& obj)
{
    length = obj.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, obj.str);
    objectCount++;
    cout << "Copy constructor\n";
}

MyString::MyString(MyString&& obj)
{
    length = obj.length;
    str = obj.str;
    obj.length = 0;
    obj.str = nullptr;
    objectCount++;
    cout << "Move constructor\n";
}

MyString::~MyString()
{
    delete[] str;
    objectCount--;
}

void MyString::Print()
{
    if (str)
    {
        cout << str << endl;
    }
    else
    {
        cout << "Empty" << endl;
    }
}

bool MyString::MyStrStr(const char* s)
{
    return strstr(str, s) != nullptr;
}

void MyString::MyStrcpy(MyString& obj)
{
    delete[] obj.str;
    obj.length = length;
    obj.str = new char[length + 1];
    strcpy_s(obj.str, length + 1, str);
}

int MyString::MyChr(char c)
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] == c)
            return i;
    }
    return -1;
}

int MyString::MyStrLen()
{
    return length;
}

void MyString::MyStrCat(MyString& b)
{
    char* temp = new char[length + b.length + 1];
    strcpy_s(temp, length + 1, str);
    strcat_s(temp, length + b.length + 1, b.str);
    delete[] str;
    str = temp;
    length += b.length;
}

void MyString::MyDelChr(char c)
{
    int newLen = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c)
        {
            str[newLen++] = str[i];
        }
    }
    str[newLen] = '\0';
    length = newLen;
}

int MyString::MyStrCmp(MyString& b)
{
    int res = strcmp(str, b.str);
    if (res < 0) return -1;
    if (res > 0) return 1;
    return 0;
}

int MyString::GetObjectCount()
{
    return objectCount;
}






// Операторы 
MyString& MyString::operator+=(const char* s)
{
    if (!s)
    {
        return *this;
    }

    int sLen = strlen(s);
    char* temp = new char[length + sLen + 1];
    strcpy_s(temp, length + 1, str);
    strcat_s(temp, length + sLen + 1, s);

    delete[] str;
    str = temp;
    length += sLen;

    return *this;
}

MyString& MyString::operator-=(const char* s)
{
    if (!str || !s)
    {
        return *this;
    }

    char* pos = strstr(str, s);
    if (pos)
    {
        int sLen = strlen(s);
        memmove(pos, pos + sLen, strlen(pos + sLen) + 1);
        length -= sLen;
    }

    return *this;
}

MyString& MyString::operator++() // добавляем запятую
{
    char* temp = new char[length + 2]; // символ + '\0'
    strcpy_s(temp, length + 1, str);
    temp[length] = ',';
    temp[length + 1] = '\0';

    delete[] str;
    str = temp;
    length += 1;

    return *this;
}

MyString& MyString::operator--() // удаляем последний символ
{
    if (length > 0)
    {
        str[length - 1] = '\0';
        length--;
    }
    return *this;
}


MyString MyString::operator++(int)
{
    MyString temp(*this);
    ++(*this);
    return temp;
}

MyString MyString::operator--(int)
{
    MyString temp(*this);
    --(*this);
    return temp;
}


bool MyString::operator==(MyString& other)
{
    if (!str && !other.str)
    {
        return true;
    }
    if (!str || !other.str)
    {
        return false;
    }
    if (strcmp(str, other.str) == 0)
    {
        return true;
    }
    return false;
}

bool MyString::operator>(MyString& other)
{
    if (!str)
    {
        return false;
    }
    if (!other.str)
    {
        return true;
    }
    if (strcmp(str, other.str) > 0)
    {
        return true;
    }
    return false;
}

bool MyString::operator!() // проверка пустой строки
{
    if (length == 0 || str[0] == '\0')
    {
        return true;
    }
    return false;
}

