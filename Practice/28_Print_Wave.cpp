#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> v;

    for (int col = 0; col < mCols; col++)
    {
        if (col & 1)
        {
            for (int row = nRows - 1; row >= 0; row--)
            {
                v.push_back(arr[row][col]);
            }
        }
        else
        {
            for (int row = 0; row < nRows; row++)
            {
                v.push_back(arr[row][col]);
            }
        }
    }

    return v;
}

int main()
{
    int nRows, mCols;
    nRows = 4;
    mCols = 4;

    vector<vector<int>> arr(nRows, vector<int>(mCols));

    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            arr[i][j] = i + j;
        }
    }

    vector<int> result = wavePrint(arr, nRows, mCols);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}