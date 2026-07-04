// Articulation Point in a Graph using DFS (Tarjan's Algorithm)

// TC: O(V + E), SC: O(V + E) for adjacency list + O(V) for disc, low, vis, isArticulation arrays

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

// DFS Helper function to find Articulation Points
void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis,
         vector<bool> &isArticulation)
{

    vis[node] = true;
    disc[node] = low[node] = timer++;
    int childCount = 0;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }

        if (!vis[nbr])
        {
            childCount++;
            dfs(nbr, node, timer, disc, low, adj, vis, isArticulation);

            // While backtracking, update low value of the parent
            low[node] = min(low[node], low[nbr]);

            // Condition 1: Non-root node check
            if (parent != -1 && low[nbr] >= disc[node])
            {
                isArticulation[node] = true;
            }
        }
        else
        {
            // Back Edge
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // Condition 2: Root node check
    if (parent == -1 && childCount > 1)
    {
        isArticulation[node] = true;
    }
}

// Main algorithm function
vector<int> findArticulationPoints(vector<vector<int>> &edges, int v, int e)
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

    // Boolean array to avoid duplicates if a vertex is an articulation point for multiple components
    vector<bool> isArticulation(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, adj, vis, isArticulation);
        }
    }

    // Collect all marked articulation points
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if (isArticulation[i])
        {
            ans.push_back(i);
        }
    }

    return ans;
}

// Driver main function
int main()
{
    int v = 5;
    int e = 5;

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

    vector<int> ap = findArticulationPoints(edges, v, e);

    cout << "Articulation Points found in the graph: " << endl;
    if (ap.empty())
    {
        cout << "No Articulation Points found." << endl;
    }
    else
    {
        for (int node : ap)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}