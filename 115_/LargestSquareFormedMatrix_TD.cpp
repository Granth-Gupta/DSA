// Largest Square Formed in Matrix - Approach 2: Top Down DP
// TC: O(n*m)  SC: O(n*m) + O(n*m) (for recursion stack space)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(mat, i, j + 1, maxi, dp);
        int down = solve(mat, i + 1, j, maxi, dp);
        int diagnol = solve(mat, i + 1, j + 1, maxi, dp);

        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(down, diagnol));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;
    }

public:
    int maxSquare(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = 0;
        solve(mat, 0, 0, maxi, dp);
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