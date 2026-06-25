// Shortest Path in an unweighter undirected graph - CN

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 1}, {2, 3}, {3, 1}, {3, 8}, {4, 1}, {4, 6}, {5, 2}, {5, 8}, {6, 4}, {6, 7}, {7, 6}, {7, 8}, {8, 3}, {8, 5}, {8, 7}};
    int s = 1;
    int t = 8;

    vector<int> path = shortestPath(edges, 8, 18, s, t);

    for (auto i : path)
        cout << i << " ";

    return 0;
}