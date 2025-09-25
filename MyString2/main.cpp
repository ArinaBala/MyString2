#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Objects before: ";
    MyString::ShowCount();

    MyString a("Hello");
    MyString b("world");

    cout << "Objects now: ";
    MyString::ShowCount();

    ++a;          // Hello + пробел
    a.Print();

    --a;          // убрали последний символ
    a.Print();

    a += "world"; // Helloworld
    a.Print();

    a -= "lo";    // Heworld
    a.Print();

    cout << "a == b ? " << (a == b) << endl;
    cout << "a > b  ? " << (a > b) << endl;

    if (a.Length() == 0)   
    {
        cout << "String is empty\n";
    }
    else
    {
        cout << "String is not empty\n";
    }

    cout << "Objects after: ";
    MyString::ShowCount();
    return 0;
}
