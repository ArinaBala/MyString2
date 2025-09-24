#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
    char* str;
    int length;
    static int objectCount;

public:
    
    MyString();
    MyString(int size);
    MyString(const char* st);
    MyString(const MyString& obj);
    MyString(MyString&& obj);
    ~MyString();

    void Print();
    bool MyStrStr(const char* s);
    void MyStrcpy(MyString& obj);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(MyString& b);
    MyString operator+(const MyString& b);

    static int GetObjectCount();

    
    MyString& operator+=(const char* s);
    MyString& operator-=(const char* s);
    MyString& operator++(); 
    MyString& operator--(); 
    MyString operator++(int);
    MyString operator--(int);
    bool operator==(MyString& other); 
    bool operator>(MyString& other);  
    bool operator!();                 
};