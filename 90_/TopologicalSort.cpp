// Topological Sort - CN - Approach (DFS)
// TC -> O(v+e)

#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int node, stack<int> &s, unordered_map<int, list<int>> &adjList,
                     vector<bool> &visited)
{
    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
            topologicalSort(neighbour, s, adjList, visited);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topologicalSort(i, s, adjList, visited);
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    int v = 6;
    int e = 7;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}, {4, 5}};
    vector<int> ans = topologicalSort(edges, v, e);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}