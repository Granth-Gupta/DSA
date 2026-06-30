// Finding Bridge using Brute force and DFS
// TC = O(E (V + E))
// SC = O(V + E)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;
    vector<pair<int, int>> edges;

    // Standard DFS that skips the "removed" edge
    void DFS(int u, vector<bool> &visited, int skipU, int skipV)
    {
        visited[u] = true;

        for (int v : adj[u])
        {
            // Check if this is the edge we are currently pretending to remove
            if ((u == skipU && v == skipV) || (u == skipV && v == skipU))
            {
                continue;
            }

            if (!visited[v])
            {
                DFS(v, visited, skipU, skipV);
            }
        }
    }

    // Helper to count connected components in the graph
    int countComponents(int skipU = -1, int skipV = -1)
    {
        vector<bool> visited(V, false);
        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                count++;
                DFS(i, visited, skipU, skipV);
            }
        }
        return count;
    }

public:
    Graph(int vertices)
    {
        this->V = vertices;
        adj.resize(vertices);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);

        // Keep pair orientation uniform (u < v) to make tracking cleaner
        if (u > v)
            swap(u, v);
        edges.push_back({u, v});
    }

    vector<pair<int, int>> findBridgesBruteForce()
    {
        vector<pair<int, int>> bridges;

        // Step 1: Find baseline component count
        int initialComponents = countComponents();

        // Step 2: Try removing each edge one by one
        for (const auto &edge : edges)
        {
            int u = edge.first;
            int v = edge.second;

            // Step 3: Count components without this specific edge
            int currentComponents = countComponents(u, v);

            // Step 4: If components increased, removing it broke connectivity -> Bridge!
            if (currentComponents > initialComponents)
            {
                bridges.push_back({u, v});
            }
        }

        return bridges;
    }
};

int main()
{
    // Setting up the graph
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    vector<pair<int, int>> bridges = g.findBridgesBruteForce();

    cout << "Bridges found via Brute Force (DFS):\n";
    for (const auto &bridge : bridges)
    {
        cout << bridge.first << " - " << bridge.second << "\n";
    }

    return 0;
}