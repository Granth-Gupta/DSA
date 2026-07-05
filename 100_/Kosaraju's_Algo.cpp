// Kosaraju's Algorithm for finding Strongly Connected Components (SCCs) in a directed graph

// TC: O(V + E), where V is the number of vertices and E is the number of edges in the graph
// SC: O(V), for storing the visited array and the stack

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list representation of the graph

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void fillOrder(int v, vector<bool> &visited, stack<int> &Stack)
    {
        visited[v] = true;

        for (int i : adj[v])
        {
            if (!visited[i])
            {
                fillOrder(i, visited, Stack);
            }
        }

        Stack.push(v);
    }

    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (int i : adj[v])
        {
            if (!visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

    Graph getTranspose()
    {
        Graph g(V);
        for (int v = 0; v < V; v++)
        {
            for (int i : adj[v])
            {
                g.adj[i].push_back(v);
            }
        }
        return g;
    }

    void printSCCs()
    {
        stack<int> Stack;
        vector<bool> visited(V, false);

        // Fill vertices in stack according to their finishing times
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                fillOrder(i, visited, Stack);
            }
        }

        // Create a transposed graph
        Graph gr = getTranspose();

        // Mark all vertices as not visited for the second DFS
        fill(visited.begin(), visited.end(), false);

        // Now process all vertices in order defined by Stack
        while (!Stack.empty())
        {
            int v = Stack.top();
            Stack.pop();

            if (!visited[v])
            {
                gr.DFSUtil(v, visited);
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(1, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Strongly Connected Components in the given graph:\n";
    g.printSCCs();

    return 0;
}
