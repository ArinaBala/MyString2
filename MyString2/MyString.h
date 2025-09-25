#pragma once
#include <iostream>
using namespace std;

class MyString
{
    char* data;
    int size;
    static int objectCounter;  

public:
    MyString();
    MyString(int s);
    MyString(const char* text);
    ~MyString();

    MyString(const MyString& object);   
    MyString(MyString&& object);        

    void Print();
    void CopyFrom(const MyString& object);   
    bool Contains(const char* sub);          
    int  FindChar(char c);                   
    int  Length();                           
    void Concat(MyString& object);           
    void RemoveChar(char c);                 
    int  Compare(MyString& object);         

    static void ShowCount();                 

    MyString operator+(MyString& object);
    MyString operator-(MyString& object);
    MyString operator*(int times);

    MyString& operator+=(const char* s);
    MyString& operator-=(const char* s);

    MyString& operator++();  
    MyString& operator--();   

    bool operator==(MyString& object);
    bool operator>(MyString& object);
};
