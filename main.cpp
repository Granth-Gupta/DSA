#include <iostream>
using namespace std;

int sqrt(int n)
{
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s < e)
    {
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int n = 36;
    int ans = sqrt(n);
    cout << ans;

    return 0;
}