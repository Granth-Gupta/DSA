#include <iostream>
using namespace std;

int main()
{
    int day = 4;

    switch (day)
    {
    case 1:
        cout << "Monday";
        // continue;    // Error: continue statement not within a switch statement
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

    cout << endl;

    while (1)
    {
        switch (1)
        {
        case 1:
            cout << "Exit used to break the loop (Break does not break the loop from switch)";
            exit(0);
            // break;
        }
    }

    return 0;
}