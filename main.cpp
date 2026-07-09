// Leetcode 852. Peak Index in a Mountain Array

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 1, 0};
    int ans = peakIndexInMountainArray(arr);

    cout << "Peak Mountain Array Index: " << ans << endl;

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    auto first = arr.data();

    cout << "First Element Address: " << first << endl;
    cout << "First Element: " << *first << endl;

    return 0;
}
