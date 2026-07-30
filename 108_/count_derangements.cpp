// Count Derangements - CN (Approach 1: Recursion)
// TC: O(2^n) SC: O(n) (Recursion stack space)

#include <iostream>
using namespace std;

#define MOD 1000000007

long long int countDerangements(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    int ans = ((n - 1) % MOD) * ((countDerangements(n - 2) % MOD) + (countDerangements(n - 1) % MOD)) % MOD;

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << countDerangements(n) << endl;
    return 0;
}