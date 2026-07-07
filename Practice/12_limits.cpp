#include <iostream>
#include <climits>
// #include <limits.h>
using namespace std;

int main()
{
    cout << "INT_MAX: " << INT_MAX << endl;     // 2147483647 -> 2^31 - 1
    cout << "INT_MIN: " << INT_MIN << endl;     // -2147483648 -> -2^31
    cout << "LONG_MAX: " << LONG_MAX << endl;   // 2147483647 -> 2^31 - 1 (or 9223372036854775807 on 64-bit systems (like Linux))
    cout << "LONG_MIN: " << LONG_MIN << endl;   // -2147483648 -> -2^31 (or -9223372036854775808 on 64-bit systems (like Linux))
    cout << "LLONG_MAX: " << LLONG_MAX << endl; // 9223372036854775807 -> 2^63 - 1
    cout << "LLONG_MIN: " << LLONG_MIN << endl; // -9223372036854775808 -> -2^63

    return 0;
}