#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    int n = 4;
    int m = 4;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    Solution sol;
    sol.rotate(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}