#include <iostream>
#include <vector>
using namespace std;

// Even long long int cannot store factorial of large numbers like 25! or 100! because they exceed the range of long long int.
// TC -> O(n^2)
// SC -> O(n)

void factorial(int n)
{
    // Vector to store the digits of the answer in reverse order
    vector<int> ans;
    ans.push_back(1);

    // Multiply numbers from 2 to n
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;

        // Multiply 'i' with every digit currently in the vector
        for (int j = 0; j < ans.size(); j++)
        {
            int prod = ans[j] * i + carry;
            ans[j] = prod % 10;
            carry = prod / 10;
        }

        // Put the remaining carry into the vector
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial of " << n << " is: ";
    factorial(n);

    return 0;
}