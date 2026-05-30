#include <iostream>
using namespace std;

int main(){
    int a = 'a';
    int b = 'A';
    int c = '0';

    cout << "ASCII value of 'a': " << a << endl;
    cout << "ASCII value of 'A': " << b << endl;
    cout << "ASCII value of '0': " << c << endl;

    // char d = 123455;
    // warning: overflow in conversion from 'int' to 'char' changes value from '123455' to '63'

    unsigned int e = -1;
    cout << "Value of unsigned int e: " << e << endl; // 4294967295

    cout << 12/5 << endl; // 2
    cout << 12.0/5 << endl; // 2.4

    return 0;
}