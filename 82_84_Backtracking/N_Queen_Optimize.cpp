// N Queen Problem - Optimized using HashMaps

// Time  : O(n!)
// Space : O(n²)

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col,
            unordered_map<int, bool> &rowCheck,
            unordered_map<int, bool> &upperDiagonalCheck,
            unordered_map<int, bool> &lowerDiagonalCheck,
            int n)
{
    if (rowCheck[row])
        return false;

    if (lowerDiagonalCheck[row + col])
        return false;

    if (upperDiagonalCheck[n - 1 + col - row])
        return false;

    return true;
}

void addSolution(vector<vector<int>> &boards,
                 vector<vector<int>> &ans,
                 int n)
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

void solve(int col,
           vector<vector<int>> &boards,
           vector<vector<int>> &ans,
           int n,
           unordered_map<int, bool> &rowCheck,
           unordered_map<int, bool> &upperDiagonalCheck,
           unordered_map<int, bool> &lowerDiagonalCheck)
{
    if (col == n)
    {
        addSolution(boards, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col,
                   rowCheck,
                   upperDiagonalCheck,
                   lowerDiagonalCheck,
                   n))
        {
            boards[row][col] = 1;

            rowCheck[row] = true;
            lowerDiagonalCheck[row + col] = true;
            upperDiagonalCheck[n - 1 + col - row] = true;

            solve(col + 1,
                  boards,
                  ans,
                  n,
                  rowCheck,
                  upperDiagonalCheck,
                  lowerDiagonalCheck);

            boards[row][col] = 0;

            rowCheck[row] = false;
            lowerDiagonalCheck[row + col] = false;
            upperDiagonalCheck[n - 1 + col - row] = false;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> boards(n, vector<int>(n, 0));

    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperDiagonalCheck;
    unordered_map<int, bool> lowerDiagonalCheck;

    solve(0,
          boards,
          ans,
          n,
          rowCheck,
          upperDiagonalCheck,
          lowerDiagonalCheck);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans = solveNQueens(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}