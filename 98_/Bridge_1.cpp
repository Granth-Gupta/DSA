#include <iostream>
#include <vector>
#include <algorithm>

class Graph
{
    int V;
    std::vector<std::vector<int>> adj;
    int time;

    void bridgeDFS(int u, std::vector<bool> &visited, std::vector<int> &discoveryTime,
                   std::vector<int> &low, int parent, std::vector<std::pair<int, int>> &bridges)
    {

        visited[u] = true;
        discoveryTime[u] = low[u] = ++time;

        for (int v : adj[u])
        {
            // If neighbor is parent, skip it
            if (v == parent)
                continue;

            if (!visited[v])
            {
                // Recur for unvisited neighbor
                bridgeDFS(v, visited, discoveryTime, low, u, bridges);

                // Check if the subtree rooted with v has a connection to one of u's ancestors
                low[u] = std::min(low[u], low[v]);

                // If the lowest vertex reachable from v is discovered strictly after u,
                // then edge (u, v) is a bridge
                if (low[v] > discoveryTime[u])
                {
                    bridges.push_back({u, v});
                }
            }
            else
            {
                // Update low value of u for parent function calls (Back-edge)
                low[u] = std::min(low[u], discoveryTime[v]);
            }
        }
    }

public:
    Graph(int vertices)
    {
        this->V = vertices;
        adj.resize(vertices);
        time = 0;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Graph is undirected
    }

    std::vector<std::pair<int, int>> findBridges()
    {
        std::vector<bool> visited(V, false);
        std::vector<int> discoveryTime(V, -1);
        std::vector<int> low(V, -1);
        std::vector<std::pair<int, int>> bridges;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bridgeDFS(i, visited, discoveryTime, low, -1, bridges);
            }
        }
        return bridges;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    std::vector<std::pair<int, int>> bridges = g.findBridges();

    std::cout << "Bridges in the graph:\n";
    for (const auto &bridge : bridges)
    {
        std::cout << bridge.first << " - " << bridge.second << "\n";
    }

    return 0;
}