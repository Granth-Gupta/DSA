// Fibonacci using matrix exponentiation
// TC: O(log n), SC: O(1)

#include <iostream>
using namespace std;

const long long MOD = 1000000007;

/*
===========================================
        FIBONACCI USING MATRIX EXPONENTIATION
===========================================

Recurrence:
F(n) = F(n-1) + F(n-2)

This can be represented as:

|F(n)    |   = |1 1| * |F(n-1)|
|F(n-1)  |     |1 0|   |F(n-2)|

Let,

A = |1 1|
    |1 0|

Then,

A^n = |F(n+1)  F(n)  |
      |F(n)    F(n-1)|

Therefore,

A^(n-1) = |F(n)   F(n-1)|
          |F(n-1) F(n-2)|

Hence,
Top-left element of A^(n-1) = F(n)

-------------------------------------------------
Why Binary Exponentiation?

Instead of multiplying A (n-1) times,

A^13 = A^8 × A^4 × A^1

Exponent is halved every time.

Time Complexity = O(log n)

--------------------
For A^9

power(A,9)
      |
      v
power(A,4)
      |
      v
power(A,2)
      |
      v
power(A,1)

Hence TC -> O(log n)
---------------------
-------------------------------------------------
Dry Run (n = 5)

Need:
F(5)

Compute:
A^(5-1) = A^4

Step 1:
A =
|1 1|
|1 0|

Step 2:
A² = A × A

|1 1|   |1 1|   |2 1|
|1 0| × |1 0| = |1 1|

Step 3:
A⁴ = A² × A²

|2 1|   |2 1|   |5 3|
|1 1| × |1 1| = |3 2|

Result:

A⁴ =
|5 3|
|3 2|

Top-left = 5

Therefore,
F(5) = 5

-------------------------------------------------
Example:

Input:
10

Need:
A^9

A^9 =
|55 34|
|34 21|

Top-left = 55

Answer = 55
===========================================
*/

struct Matrix
{
    long long a, b, c, d;
};

// Multiply two 2×2 matrices
Matrix multiply(Matrix x, Matrix y)
{
    Matrix res;

    /*
        |a b|   |e f|
        |c d| × |g h|

        =

        |ae+bg   af+bh|
        |ce+dg   cf+dh|
    */

    res.a = (x.a * y.a + x.b * y.c) % MOD;
    res.b = (x.a * y.b + x.b * y.d) % MOD;
    res.c = (x.c * y.a + x.d * y.c) % MOD;
    res.d = (x.c * y.b + x.d * y.d) % MOD;

    return res;
}

// Computes base^n using Binary Exponentiation
Matrix power(Matrix base, long long n)
{
    // Base case
    if (n == 1)
        return base;

    /*
        Example:
        power(A, 9)

                 9
                / \
               4   A
              /
             2
            /
           1

        A^9 = (A^4 × A^4) × A
    */

    Matrix half = power(base, n / 2);

    // Square
    Matrix ans = multiply(half, half);

    // Multiply once more if exponent is odd
    if (n % 2)
        ans = multiply(ans, base);

    return ans;
}

long long fibonacci(long long n)
{
    /*
        F(0) = 0
        F(1) = 1
    */

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    Matrix base = {1, 1, 1, 0};

    // Compute A^(n-1)
    Matrix ans = power(base, n - 1);

    // Top-left element = F(n)
    return ans.a;
}

int main()
{
    long long n;
    cin >> n;

    cout << fibonacci(n);

    return 0;
}