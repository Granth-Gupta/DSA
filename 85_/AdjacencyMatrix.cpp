// Implementation of Adjacency Matrix to represent graph

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1; // Remove for directed graph
    }

    // Sample input

    // 5 6 -> V = 5, E = 6
    // 0 1
    // 0 2
    // 1 2
    // 1 3
    // 2 4
    // 3 4

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}