// Largest square formed in a matrix - CN (Approach: Simple Recursion)
// TC: O(3^(n*m))  SC: O(n*m) (for recursion stack space)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi)
    {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        int right = solve(mat, i, j + 1, maxi);
        int down = solve(mat, i + 1, j, maxi);
        int diagnol = solve(mat, i + 1, j + 1, maxi);

        if (mat[i][j] == 1)
        {
            int ans = 1 + min(right, min(down, diagnol));
            maxi = max(maxi, ans);
            return ans;
        }
        else
            return 0;
    }

public:
    int maxSquare(vector<vector<int>> &mat)
    {
        int maxi = 0;
        solve(mat, 0, 0, maxi);
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