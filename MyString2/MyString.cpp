#include "MyString.h"
#include <cstring>

int MyString::objectCounter = 0;

MyString::MyString()
{
    size = 80;
    data = new char[size] {};
    objectCounter++;
}

MyString::MyString(int s)
{
    size = s;
    data = new char[size] {};
    objectCounter++;
}

MyString::MyString(const char* text)
{
    size = strlen(text);
    data = new char[size + 1];
    strcpy_s(data, size + 1, text);
    objectCounter++;
}

MyString::~MyString()
{
    delete[] data;
    data = nullptr;
    size = 0;
    objectCounter--;
}

void MyString::Print()
{
    cout << data << endl;
}

void MyString::CopyFrom(const MyString& object)
{
    if (this == &object) 
    { 
        return;
    }
    delete[] data;
    size = object.size;
    data = new char[size + 1];
    strcpy_s(data, size + 1, object.data);
}

MyString::MyString(const MyString& object)
{
    size = object.size;
    data = new char[size + 1];
    strcpy_s(data, size + 1, object.data);
    objectCounter++;
}

MyString::MyString(MyString&& object)
{
    data = object.data;
    size = object.size;

    object.data = nullptr;
    object.size = 0;
}

bool MyString::Contains(const char* sub)
{
    return strstr(this->data, sub) != nullptr;
}

int MyString::FindChar(char c)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == c) return i;
    }
    return -1;
}

int MyString::Length()
{
    return strlen(data);
}

void MyString::Concat(MyString& object)
{
    int lenA = strlen(this->data);
    int lenB = strlen(object.data);
    char* temp = new char[lenA + lenB + 1];

    strcpy_s(temp, lenA + lenB + 1, this->data);
    strcat_s(temp, lenA + lenB + 1, object.data);

    delete[] this->data;
    this->data = temp;
    this->size = lenA + lenB;
}

void MyString::RemoveChar(char c)
{
    int keep = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] != c)
        {
            keep++;
        }
    }

    char* temp = new char[keep + 1];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] != c)
        {
            temp[j++] = data[i];
        }
    }
    temp[j] = '\0';

    delete[] data;
    data = temp;
    size = keep;
}
int MyString::Compare(MyString& object)
{
    int cmp = strcmp(this->data, object.data);
    
    if (cmp < 0) 
    {
        return -1;
    }
    if (cmp > 0) 
    {
        return 1;
    }
    return 0;
}

void MyString::ShowCount()
{
    cout << "Objects: " << objectCounter << endl;
}

MyString MyString::operator+(MyString& object)
{
    MyString temp;
    delete[] temp.data;
    temp.size = this->size + object.size;
    temp.data = new char[temp.size + 1];

    strcpy_s(temp.data, this->size + 1, this->data);
    strcat_s(temp.data, temp.size + 1, object.data);
    return temp;
}

MyString MyString::operator-(MyString& object)
{
    MyString temp(*this);
    for (int i = 0; i < object.size; i++)
        {
        temp.RemoveChar(object.data[i]);
        }
    return temp;
}

MyString MyString::operator*(int times)
{
    if (times <= 0)
    {
        return MyString("");
    }
    MyString temp;
    delete[] temp.data;
    temp.size = this->size * times;
    temp.data = new char[temp.size + 1];
    temp.data[0] = '\0';

    for (int i = 0; i < times; i++)
        {
        strcat_s(temp.data, temp.size + 1, this->data);
        }
    return temp;
}

MyString& MyString::operator+=(const char* s)
{
    int addLen = strlen(s);
    char* temp = new char[size + addLen + 1];

    strcpy_s(temp, size + 1, data);
    strcat_s(temp, size + addLen + 1, s);

    delete[] data;
    data = temp;
    size += addLen;
    return *this;
}

MyString& MyString::operator-=(const char* s)
{
    int rm = strlen(s);
    
    for (int i = 0; i < rm; i++)
        {
        RemoveChar(s[i]);
        }
    return *this;
}

MyString& MyString::operator++()
{
    char* temp = new char[size + 2];
    strcpy_s(temp, size + 2, data);
    temp[size] = ' ';
    temp[size + 1] = '\0';

    delete[] data;
    data = temp;
    size++;
    return *this;
}

MyString& MyString::operator--()
{
    if (size > 0)
    {
        data[size - 1] = '\0';
        size--;
    }
    return *this;
}

bool MyString::operator==(MyString& object)
{
    return strcmp(this->data, object.data) == 0;
}

bool MyString::operator>(MyString& object)
{
    return strcmp(this->data, object.data) > 0;
}
