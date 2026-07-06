// Bellman Ford Algorithm - For Shortest distance b/w two nodes in a graph with negative weights
// Time Complexity: O(n*m) where n is the number of vertices and m is the number of edges

#include <iostream>
#include <vector>

using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Initialize distances from src to all other vertices as 1e9 (infinity)
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // Relax all edges (n - 1) times
    for (int i = 1; i < n; i++)
    {
        // Traverse on edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
        {
            flag = 1;
            break; // Found a negative cycle, can break early
        }
    }

    // If no negative cycle is found, return the destination's shortest distance
    if (flag == 0)
    {
        return dist[dest];
    }

    // Return -1 if a negative cycle is detected
    return -1;
}

int main()
{
    int n = 4;
    int m = 4;

    int src = 1;
    int dest = 4;

    // Edges format: {u, v, weight}
    vector<vector<int>> edges = {
        {1, 2, 4},
        {1, 3, 3},
        {2, 4, 7},
        {3, 4, -2}};

    int result = bellmonFord(n, m, src, dest, edges);

    if (result == -1)
    {
        cout << "The graph contains a negative weight cycle." << endl;
    }
    else
    {
        cout << "Shortest distance from node " << src << " to node " << dest << " is: " << result << endl;
    }

    return 0;
}