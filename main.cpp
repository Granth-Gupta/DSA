#include <iostream>
using namespace std;

int main()
{
    int a = 3;

    if (true)
    {
        int a = 5;
        cout << "Inner a: " << a << endl; // This will print 5
    }

    cout << "Outer a: " << a << endl; // This will print 3
}