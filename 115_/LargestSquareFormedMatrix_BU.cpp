// Largest Square Formed in Matrix - Approach 3: Bottom Up DP
// TC: O(n*m)  SC: O(n*m)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<vector<int>> &mat, int &maxi)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int row = n - 1; row >= 0; row--)
        {
            for (int col = m - 1; col >= 0; col--)
            {
                int right = dp[row][col + 1];
                int down = dp[row + 1][col];
                int diagnol = dp[row + 1][col + 1];

                if (mat[row][col] == 1)
                {
                    dp[row][col] = 1 + min(right, min(down, diagnol));
                    maxi = max(maxi, dp[row][col]);
                }
                else
                    dp[row][col] = 0;
            }
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