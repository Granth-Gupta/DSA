#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int arr[][4] = {{0, 1, 0, 0}, {0, 2, 1, 0}, {0, 10, 5, 2}, {3, 4, 5, 1}, {24, 69, 100, 99}};

    string s = "Hello, World!";
    string subStr = "l";

    while (s.size() > 0 && s.find(subStr) != string::npos)
    {
        s.erase(s.find(subStr), subStr.length());
    }

    return 0;
}