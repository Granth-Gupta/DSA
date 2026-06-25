// Cycle Detection in Directed Graph using Khan's Algo (BFS)

#include <bits/stdc++.h>
using namespace std;

bool isCyclePresent(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    vector<int> indegree(v);
    for (auto i : adjList)
    {
        for (auto j : i.second)
            indegree[j]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;

        for (auto neighbour : adjList[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    if (count == v)
        return false;
    else
        return true;
}

int main()
{
    int v = 6;
    int e = 7;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}, {4, 5}};
    bool ans = isCyclePresent(edges, v, e);

    cout << "Is Cycle Present: " << ans;

    return 0;
}