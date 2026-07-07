// Print factorial using loop

// TC -> O(n)
// SC -> O(1)

#include <iostream>
using namespace std;

int factorial(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = factorial(n);
    cout << "Factorial of " << n << " is: " << result << endl;

    return 0;
}