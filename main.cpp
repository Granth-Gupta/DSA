#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int a = 1;

    switch (a)
    {
    case 1:
        cout << "Case 1" << endl;
        break;
    case 2:
        cout << "Case 2" << endl;
        break;
    default:
        cout << "Default case" << endl;
        break;
    }

    return 0;
}