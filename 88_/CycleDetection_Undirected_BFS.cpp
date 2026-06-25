// Cycle Detection In Undirected Graph - CN - Approach#1 -> BFS

#include <bits/stdc++.h>
using namespace std;

bool checkCycleBFS(int node, unordered_map<int, int> &visited, unordered_map<int, list<int>> &adjList, int n)
{
    unordered_map<int, int> parent;

    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front])
        {
            if (visited[neighbour] == 1 && neighbour != parent[front])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
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

    unordered_map<int, int> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool isCycle = checkCycleBFS(i, visited, adjList, n);
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