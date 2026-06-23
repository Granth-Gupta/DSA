#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if the next move is valid
bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited)
{
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == 0);
}

// Recursive function to find all paths
void solveMaze(int x, int y, int n, vector<vector<int>> &maze,
               vector<vector<int>> &visited, string path, vector<string> &paths)
{
    // If destination is reached
    if (x == n - 1 && y == n - 1)
    {
        paths.push_back(path);
        return;
    }

    // Mark current cell as visited
    visited[x][y] = 1;

    // Move Down
    if (isSafe(x + 1, y, n, maze, visited))
        solveMaze(x + 1, y, n, maze, visited, path + "D", paths);

    // Move Left
    if (isSafe(x, y - 1, n, maze, visited))
        solveMaze(x, y - 1, n, maze, visited, path + "L", paths);

    // Move Right
    if (isSafe(x, y + 1, n, maze, visited))
        solveMaze(x, y + 1, n, maze, visited, path + "R", paths);

    // Move Up
    if (isSafe(x - 1, y, n, maze, visited))
        solveMaze(x - 1, y, n, maze, visited, path + "U", paths);

    // Backtrack: Unmark the cell
    visited[x][y] = 0;
}

int main()
{
    int n;
    cout << "Enter maze size (n x n): ";
    if (!(cin >> n) || n <= 0)
    {
        cout << "Invalid size.\n";
        return 1;
    }

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter maze matrix (1 = open, 0 = blocked):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(cin >> maze[i][j]) || (maze[i][j] != 0 && maze[i][j] != 1))
            {
                cout << "Invalid input. Only 0 or 1 allowed.\n";
                return 1;
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> paths;

    if (maze[0][0] == 1)
    {
        solveMaze(0, 0, n, maze, visited, "", paths);
    }

    if (paths.empty())
    {
        cout << "No path found.\n";
    }
    else
    {
        cout << "Possible paths:\n";
        for (const string &p : paths)
        {
            cout << p << "\n";
        }
    }

    return 0;
}
