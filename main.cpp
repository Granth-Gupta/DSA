class Solution
{
public:
    int findDuplicate(vector<int> &arr)
    {
        map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }

        for (int j = 0; j < arr.size(); j++)
        {
            if (m[arr[j]] != 1)
            {
                return arr[j];
            }
        }
        return 0;
    }
};