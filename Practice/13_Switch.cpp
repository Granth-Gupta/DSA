#include <iostream>
using namespace std;

int main()
{
    int day = 4;

    switch (day)
    {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    // case 3.4: // Error: case label must not be a float
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    // case "Hello": // Error: case label must not be a string
    default:
        cout << "Invalid day";
    }

    return 0;
}