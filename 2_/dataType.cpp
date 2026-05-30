#include <iostream>
using namespace std;

int main() {
    cout << "Size of short: " << sizeof(short) << " bytes\n";
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of long: " << sizeof(long) << " bytes\n";
    cout << "Size of long long: " << sizeof(long long) << " bytes\n";
    cout << "Size of bool: " << sizeof(bool) << " byte\n";

    // Size of short: 2 bytes
    // Size of int: 4 bytes
    // Size of long: 4 bytes
    // Size of long long: 8 bytes

    int a = 10;
    char b = 'A';
    float c = 3.14;
    double d = 3.14159;
    bool e = true;

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Value of c: " << c << endl;
    cout << "Value of d: " << d << endl;
    cout << "Value of e: " << e << endl;

    return 0;
}
