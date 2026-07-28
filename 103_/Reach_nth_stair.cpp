// Count ways to reach nth stair when you can take 1 or 2 steps at a time (with no DP approach).
// TLE may occur for large nStairs values as no memoization is used in this approach.

// TC: O(2^n) where n is the number of stairs
// SC: O(n) for recursion stack

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int solve(int nStairs, int i)
{
    if (i == nStairs)
        return 1;

    if (i > nStairs)
        return 0;

    int val = solve(nStairs, i + 1) + solve(nStairs, i + 2);
    val = val % MOD;
    return val;
}

int countDistinctWays(int nStairs)
{
    int ans = solve(nStairs, 0);

    return ans;
}

int main()
{
    int nStairs;
    cin >> nStairs;

    cout << countDistinctWays(nStairs) << endl;

    return 0;
}