class Solution
{
    int findIndex(vector<int> &nums, int val, int pos)
    {
        if (pos == 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == val)
                    return i;
            }
        }
        else
        {
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[i] == val)
                    return i;
            }
        }
        return -1;
    }

public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> nums_ = nums;
        sort(nums_.begin(), nums_.end());
        int s = 0;
        int e = nums.size() - 1;

        vector<int> ans;

        while (s < e)
        {
            int sum = nums_[s] + nums_[e];
            if (sum > target)
                e--;
            else if (sum == target)
            {
                ans.push_back(findIndex(nums, nums_[s], 0));
                ans.push_back(findIndex(nums, nums_[e], 1));
                return ans;
            }
            else
            {
                s++;
            }
        }
        return ans;
    }
};