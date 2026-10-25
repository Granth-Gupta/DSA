#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int s = nums[i] + nums[left] + nums[right];
                if (s < 0)
                {
                    left++;
                }
                else if (s > 0)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};