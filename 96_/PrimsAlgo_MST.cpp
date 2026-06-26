// Find Minimum spanning Tree (Prim's Algorithm)
// TC -> O(n^2)  {Priority_queue can be used to fing min to reduce TC -> O(nlogn)}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // 2. Initialize data structures
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // 3. Let's start the algo with the first node
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {

        int mini = INT_MAX;
        int u = -1;

        // Find the minimum key node that is not yet part of the MST
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // Safety check if the graph is disconnected
        if (u == -1)
            break;

        // Mark the minimum node as true (included in MST)
        mst[u] = true;

        // Check its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // 4. Structure the final result structure
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        if (parent[i] != -1)
        {
            result.push_back({{parent[i], i}, key[i]});
        }
    }

    return result;
}

int main()
{
    // Hardcoded graph parameters
    // n = 5 nodes (numbered 1 to 5)
    // m = 6 edges
    int n = 5;
    int m = 6;

    // Graph representation: {{u, v}, weight}
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 2},
        {{1, 4}, 6},
        {{2, 3}, 3},
        {{2, 4}, 8},
        {{2, 5}, 5},
        {{3, 5}, 7}};

    cout << "Calculating Prim's MST for the hardcoded graph..." << endl;
    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, g);

    cout << "\nEdges in the Minimum Spanning Tree:" << endl;
    cout << "u - v \t Weight" << endl;
    int totalWeight = 0;
    for (auto edge : mst)
    {
        cout << edge.first.first << " - " << edge.first.second << " \t " << edge.second << endl;
        totalWeight += edge.second;
    }

    cout << "\nTotal MST Weight: " << totalWeight << endl;

    return 0;
}