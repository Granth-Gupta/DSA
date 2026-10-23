#include <map>

class Solution
{
public:
    int uniqueElement(vector<int> &arr, int k)
    {
        map<int, int> m;

        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }

        for (int j = 0; j < arr.size(); j++)
        {
            if (m[arr[j]] % k != 0)
            {
                return arr[j];
            }
        }
    }
};