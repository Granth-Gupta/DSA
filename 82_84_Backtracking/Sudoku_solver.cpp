// Sudoku Solver - CN
// TC-> O(9^m) ----- m -> number of empty blocks
// SC -> O(1) ------ As max recursive calls are 81 , O(81) ~ O(1)

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int num)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[row][i] == num)
            return false;
        if (board[i][col] == num)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (board[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(i, j, board, num))
                    {
                        board[i][j] = num;
                        bool aagaSolutionPossible = solve(board);
                        if (aagaSolutionPossible)
                            return true;
                        else
                        {
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{
    vector<vector<int>> sudoku = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solveSudoku(sudoku);

    cout << "Solved Sudoku:\n";

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}