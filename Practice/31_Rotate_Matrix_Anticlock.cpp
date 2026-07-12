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

    vector<vector<int>> rotatedMatrix = rotateMatrix(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}