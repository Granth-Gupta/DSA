// N Queen Problem - Optimized using Vectors

// Time  : O(n!)
// Space : O(n²)

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col,
            vector<int> &rowCheck,
            vector<int> &upperDiagonalCheck,
            vector<int> &lowerDiagonalCheck,
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

void addSolution(vector<vector<int>> &board,
                 vector<vector<int>> &ans,
                 int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

void solve(int col,
           vector<vector<int>> &board,
           vector<vector<int>> &ans,
           int n,
           vector<int> &rowCheck,
           vector<int> &upperDiagonalCheck,
           vector<int> &lowerDiagonalCheck)
{
    if (col == n)
    {
        addSolution(board, ans, n);
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
            // Place Queen
            board[row][col] = 1;
            rowCheck[row] = 1;
            lowerDiagonalCheck[row + col] = 1;
            upperDiagonalCheck[n - 1 + col - row] = 1;

            solve(col + 1,
                  board,
                  ans,
                  n,
                  rowCheck,
                  upperDiagonalCheck,
                  lowerDiagonalCheck);

            // Backtrack
            board[row][col] = 0;
            rowCheck[row] = 0;
            lowerDiagonalCheck[row + col] = 0;
            upperDiagonalCheck[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<int> rowCheck(n, 0);
    vector<int> upperDiagonalCheck(2 * n - 1, 0);
    vector<int> lowerDiagonalCheck(2 * n - 1, 0);

    solve(0,
          board,
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

    for (auto &solution : ans)
    {
        for (int val : solution)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}