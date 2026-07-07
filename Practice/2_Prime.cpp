// Find Prime numbers between 1 to 50

// TC: O(n^2)

#include <iostream>
using namespace std;

void prime(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (i <= 1)
            continue;
        bool isPrime = true;

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime && i > 1)
            cout << i << " ";
    }
}

int main()
{
    prime(1, 50);

    return 0;
}