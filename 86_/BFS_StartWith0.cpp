// BFS in Graph - CN (Only include nodes which can be reached from 0)

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> ans;
    vector<bool> visited(n, false);

    bfs(adj, visited, ans, 0);

    return ans;
}

int main()
{
    int n;
    cin >> n; // Number of vertices

    vector<vector<int>> adj(n);

    // Input adjacency list
    for (int i = 0; i < n; i++)
    {
        int k; // Number of neighbours of vertex i
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            int neighbour;
            cin >> neighbour;
            adj[i].push_back(neighbour);
        }
    }

    // 6
    // 3 1 2 3
    // 1 4
    // 1 5
    // 0
    // 0
    // 0

    vector<int> result = bfsTraversal(n, adj);

    cout << "BFS Traversal: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}