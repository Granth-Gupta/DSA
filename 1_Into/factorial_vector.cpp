#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> digits;
    digits.push_back(1); // Initially, factorial = 1

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;

        for (int j = 0; j < digits.size(); j++)
        {
            int product = digits[j] * i + carry;

            digits[j] = product % 10;
            carry = product / 10;
        }

        while (carry > 0)
        {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Print digits in reverse order
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        cout << digits[i];
    }

    cout << '\n';
    return 0;
}
