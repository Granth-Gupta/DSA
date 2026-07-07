#include <bits/stdc++.h>
using namespace std;

// Factorial of large numbers using string to store the result - CN
// TC -> O(n^2)
// SC -> O(n)

string calculateFactorial(int n)
{
    string ans = "";
    // Store raw integer 1 as a byte character
    ans.push_back(1);

    // Multiply numbers from 2 to n
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;

        // Multiply 'i' with every digit currently in the string
        for (int j = 0; j < ans.size(); j++)
        {
            // ans[j] holds a raw integer (0-9), so we can multiply directly
            int prod = ans[j] * i + carry;
            ans[j] = prod % 10;
            carry = prod / 10;
        }

        // Put the remaining carry into the string
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Convert raw integers (0-9) to visible ASCII characters ('0'-'9')
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = ans[i] + '0';
    }

    // Reverse the string so it reads correctly from left to right
    reverse(ans.begin(), ans.end());

    return ans;
}