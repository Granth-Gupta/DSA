// Cycle Detection In directed Graph - CN - Approach#1 -> DFS

#include <bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited,
                   unordered_map<int, bool> &DFSvisited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    DFSvisited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycleFound = checkCycleDFS(neighbour, visited, DFSvisited, adjList);
            if (cycleFound)
                return true;
        }
        else if (DFSvisited[neighbour])
            return true;
    }

    DFSvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, DFSvisited, adjList);
            if (cycleFound)
                return true;
        }
    }

    return false;
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

        bool ans = detectCycleInDirectedGraph(n, edges);
        if (ans)
            cout << "\nCycle Present" << endl;
        else
            cout << "\nCycle Absent" << endl;
    }

    return 0;
}