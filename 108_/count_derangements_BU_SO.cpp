// Count Derangements - CN (Approach 4: Bottom Up + Space Optimization)
// TC: O(n) SC: O(1) (Constant space)

#include <iostream>
using namespace std;

#define MOD 1000000007

long long int solve(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    long long int prev2 = 0;
    long long int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        int curr = ((i - 1) % MOD) * ((prev2 % MOD) + (prev1 % MOD)) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int countDerangements(int n)
{
    return solve(n);
}

int main()
{
    int n;
    cin >> n;
    cout << countDerangements(n) << endl;
    return 0;
}
