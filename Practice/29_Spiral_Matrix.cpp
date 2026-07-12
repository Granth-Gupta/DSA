#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m)
{
    int u = 0, d = n - 1;
    int l = 0, r = m - 1;

    vector<int> order;

    while (u <= d && l <= r)
    {
        // Traverse left to right
        for (int col = l; col <= r; col++)
            order.push_back(matrix[u][col]);
        u++;

        // Traverse top to bottom
        for (int row = u; row <= d; row++)
            order.push_back(matrix[row][r]);
        r--;

        // Traverse right to left
        if (u <= d)
        {
            for (int col = r; col >= l; col--)
                order.push_back(matrix[d][col]);
            d--;
        }

        // Traverse bottom to top
        if (l <= r)
        {
            for (int row = d; row >= u; row--)
                order.push_back(matrix[row][l]);
            l++;
        }
    }

    return order;
}