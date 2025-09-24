#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Objects before: " << MyString::GetObjectCount() << endl;

    MyString a("Hello");
    MyString b("world");

    cout << "Objects now: " << MyString::GetObjectCount() << endl;

    a++;          // Hello,
    a.Print();

    a--;          // Hello
    a.Print();

    a += "world"; // Helloworld
    a.Print();

    a -= "lo";    // Helworld
    a.Print();

    cout << (a == b) << endl;
    cout << (a > b) << endl;

    if (!a)
    {
        cout << "String is empty\n";
    }
    else
    {
        cout << "String is not empty\n";
    }

    cout << "Objects after: " << MyString::GetObjectCount() << endl;
    return 0;
}