#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each column
    for (int j = 0; j < n; j++)
    {
        int top = 0, bottom = n - 1;
        while (top < bottom)
        {
            swap(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    }

    return matrix;
}