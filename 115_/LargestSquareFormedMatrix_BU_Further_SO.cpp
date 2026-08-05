// Largest Square Formed in a Matrix (Bottom-Up Approach with in-place modification of the input matrix)
// TC: O(n*m)  SC: O(1) (In-place modification of the input matrix)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSquare(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 0;

        for (int row = n - 1; row >= 0; row--)
        {
            for (int col = m - 1; col >= 0; col--)
            {
                // Base case handling: Last row or last column cannot extend downward/rightward
                if (row == n - 1 || col == m - 1)
                {
                    maxi = max(maxi, mat[row][col]);
                    continue;
                }

                // If current cell is 1, calculate max square size using adjacent values
                if (mat[row][col] == 1)
                {
                    int right = mat[row][col + 1];
                    int down = mat[row + 1][col];
                    int diagonal = mat[row + 1][col + 1];

                    mat[row][col] = 1 + min({right, down, diagonal});
                    maxi = max(maxi, mat[row][col]);
                }
            }
        }
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