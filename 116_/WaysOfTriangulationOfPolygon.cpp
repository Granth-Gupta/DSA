// Number of ways of Triangulation for a Polygon - using catalan number
// Catalan Number : 1 1 2 5 14 42 132 429 1430 4862 ...
// TC: O(n), SC: O(1)

// Cn ​= (2n)!/(n+1)!n! {Formula for Catalan Number}

// C++ code of finding Number of ways a convex polygon of n+2
// sides can split into triangles by connecting vertices
#include <iostream>
using namespace std;

// Function to calculate the binomial coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    // C(n, k) is the same as C(n, n-k)
    if (k > n - k)
        k = n - k;

    int res = 1;
    // Calculate the value of n! / (k! * (n-k)!)
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Function to find the nth Catalan number
int countWays(int n)
{
    n = n - 2;
    // Calculate C(2n, n)
    int c = binomialCoeff(2 * n, n);
    // Return the nth Catalan number
    return c / (n + 1);
}

int main()
{
    int n = 7;
    cout << countWays(n) << endl;
    return 0;
}