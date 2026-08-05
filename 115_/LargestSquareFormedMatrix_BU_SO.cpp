// Largest Square Formed in Matrix - Approach 4: Bottom Up DP + Space Optimization
// TC: O(n*m)  SC: O(m)

// Note: SC can be O(n). The choice of implementation can affect the space complexity.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<vector<int>> &mat, int &maxi)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int row = n - 1; row >= 0; row--)
        {
            for (int col = m - 1; col >= 0; col--)
            {
                int right = curr[col + 1];
                int down = next[col];
                int diagnol = next[col + 1];

                if (mat[row][col] == 1)
                {
                    curr[col] = 1 + min(right, min(down, diagnol));
                    maxi = max(maxi, curr[col]);
                }
                else
                    curr[col] = 0;
            }
            next = curr;
        }
    }

public:
    int maxSquare(vector<vector<int>> &mat)
    {

        int maxi = 0;
        solve(mat, maxi);
        return maxi;
    }
};

int main()
{
    vector<vector<int>> mat = {{0, 1, 1, 0, 1},
                               {1, 1, 0, 1, 0},
                               {0, 1, 1, 1, 0},
                               {1, 1, 1, 1, 0},
                               {1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0}};

    Solution obj;
    int ans = obj.maxSquare(mat);
    cout << "The size of the largest square formed in the matrix is: " << ans << endl;

    return 0;
}