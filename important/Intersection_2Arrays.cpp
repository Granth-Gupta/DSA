class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> ans;

        for (int x : nums2)
        {
            if (set1.count(x))
            {
                ans.push_back(x);
                set1.erase(x); // Prevents duplicates in ans and speeds up future checks
            }
        }
        return ans;
    }
};