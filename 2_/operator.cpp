#include <iostream>
using namespace std;

int main(){
    // Relational operators
    int a = 10, b = 20, c = 30;

    cout << "a > b: " << (a > b) << endl; // 0
    cout << "a < b: " << (a < b) << endl; // 1
    cout << "a == c: " << (a == c) << endl; // 0
    cout << "a != c: " << (a != c) << endl; // 1


    // bitwise operators
    int x = 5; // 0101 in binary
    int y = 3; // 0011 in binary

    cout << "x & y: " << (x & y) << endl; // 1 (0001 in binary)
    cout << "x | y: " << (x | y) << endl; // 7 (0111 in binary)
    cout << "x ^ y: " << (x ^ y) << endl; // 6 (0110 in binary)

    // Logical operators
    bool p = true, q = false;

    cout << "p && q: " << (p && q) << endl; // 0
    cout << "p || q: " << (p || q) << endl; // 1

    int r = 5;
    cout << "!r: " << (!r) << endl; // 0

    return 0;
}