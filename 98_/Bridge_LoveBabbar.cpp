// Bridge - DFS Approach - O(V + E)

// TC = O(V + E)
// SC = O(V + E)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

// DFS Helper function to find bridges using Tarjan's Algorithm
void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis)
{

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }

        if (!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            // Check if the edge is a bridge
            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            // Back Edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

// Main algorithm function
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int val_v = edges[i][1];

        adj[u].push_back(val_v);
        adj[val_v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;
    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}

// Driver main function
int main()
{
    // Number of vertices and edges
    int v = 5;
    int e = 5;

    // Defining the edges of the graph
    // Graph representation:
    // 0 - 1 - 2 - 0 (Cycle)
    // 0 - 3
    // 3 - 4
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {0, 3},
        {3, 4}};

    vector<vector<int>> bridges = findBridges(edges, v, e);

    cout << "Bridges found in the graph: " << endl;
    if (bridges.empty())
    {
        cout << "No bridges found." << endl;
    }
    else
    {
        for (const auto &bridge : bridges)
        {
            cout << bridge[0] << " -- " << bridge[1] << endl;
        }
    }

    return 0;
}