// N Queen Problem - CN

// Time  : O(n! · n)
// Space : O(n²)

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &boards, int n)
{
    int x = row;
    int y = col;

    while (y >= 0)
    {
        if (boards[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    x = row;
    y = col;

    while (x >= 0 && y >= 0)
    {
        if (boards[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;

    while (x < n && y >= 0)
    {
        if (boards[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }
    return true;
}

void addSolution(vector<vector<int>> &boards, vector<vector<int>> &ans, int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(boards[i][j]);
        }
    }

    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &boards, vector<vector<int>> &ans, int n)
{
    if (col == n)
    {
        addSolution(boards, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, boards, n))
        {
            boards[row][col] = 1;
            solve(col + 1, boards, ans, n);
            boards[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> boards(n, vector<int>(n, 0));

    solve(0, boards, ans, n);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans = solveNQueens(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < n * n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}