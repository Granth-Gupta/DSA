// Cycle Detection In Undirected Graph - CN - Approach#1 -> DFS

#include <bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(neighbour, node, visited, adjList);
            if (cycleDetected)
                return true;
        }
        else if (neighbour != parent)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool isCycle = checkCycleDFS(i, -1, visited, adjList);
            if (isCycle)
                return "Yes";
        }
    }
    return "No";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges(m, vector<int>(2));

        for (int i = 0; i < m; i++)
        {
            cin >> edges[i][0] >> edges[i][1];
        }

        cout << cycleDetection(edges, n, m) << endl;
    }

    return 0;
}