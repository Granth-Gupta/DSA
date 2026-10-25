// Leetcode 852. Peak Index in a Mountain Array

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int e = arr.size() - 1;
    int s = 0;

    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{
    vector<int> arr = {0, 1, 2, 1, 0};
    int ans = peakIndexInMountainArray(arr);

    cout << "Peak Mountain Array Index: " << ans << endl;
}
