#include <iostream>
using namespace std;

// Optimized Prime Finder
// Time Complexity: O(n * sqrt(n))

void prime(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (i <= 1)
            continue;
        bool isPrime = true;

        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            cout << i << " ";
    }
    cout << endl;
}

int main()
{
    prime(1, 50);
    return 0;
}