#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    int firstOccurence(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] < target)
                s = mid + 1;
            else if (nums[mid] > target)
                e = mid - 1;
            else
            {
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }

    int lastOccurence(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] < target)
                s = mid + 1;
            else if (nums[mid] > target)
                e = mid - 1;
            else
            {
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = firstOccurence(nums, target);
        int last = lastOccurence(nums, target);

        return {first, last};
    }
};