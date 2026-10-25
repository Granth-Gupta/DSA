#include <vector>
#include <algorithm>

using namespace std;

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> res;
//         int n = nums.size();

//         for (int i = 0; i < n - 2; ++i)
//         {
//             if (nums[i] > 0)
//             {
//                 break;
//             }
//             if (i > 0 && nums[i] == nums[i - 1])
//             {
//                 continue;
//             }

//             int left = i + 1;
//             int right = n - 1;

//             while (left < right)
//             {
//                 int s = nums[i] + nums[left] + nums[right];
//                 if (s < 0)
//                 {
//                     left++;
//                 }
//                 else if (s > 0)
//                 {
//                     right--;
//                 }
//                 else
//                 {
//                     res.push_back({nums[i], nums[left], nums[right]});
//                     left++;
//                     right--;

//                     // Skip duplicates for left pointer
//                     while (left < right && nums[left] == nums[left - 1])
//                     {
//                         left++;
//                     }
//                     // Skip duplicates for right pointer
//                     while (left < right && nums[right] == nums[right + 1])
//                     {
//                         right--;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 1. Store the size in an integer to prevent unsigned integer underflow
        // if nums.size() < 2, and to avoid calling .size() repeatedly.
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++)
        {
            // 2. Early Pruning: If the current number is greater than 0,
            // the remaining numbers (which are even larger) can never sum to 0.
            if (nums[i] > 0)
                break;

            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int s = i + 1;
            int e = n - 1;
            int target = -nums[i];

            while (s < e)
            {
                int current_sum = nums[s] + nums[e];

                if (current_sum == target)
                {
                    // 3. Direct Initialization: Avoid creating a temporary vector
                    // and calling push_back 3 times. This is much faster.
                    result.push_back({nums[i], nums[s], nums[e]});

                    s++;
                    e--;

                    while (s < e && nums[s] == nums[s - 1])
                        s++;
                    while (s < e && nums[e] == nums[e + 1])
                        e--;
                }
                else if (current_sum < target)
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
        return result;
    }
};