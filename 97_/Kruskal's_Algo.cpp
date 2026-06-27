// Kruskal's Algorithm - CN

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator function to sort edges based on their weights
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

// Initializes the parent and rank arrays
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Finds the representative (parent) of the set containing 'node' with Path Compression
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

// Unites two sets based on their ranks
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal's Algorithm to find the Minimum Spanning Tree
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{

    // 1. Sort the edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), cmp);

    // 2. Initialize parent and rank structures
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    // 3. Process each sorted edge
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int weight = edges[i][2];

        // If including this edge doesn't form a cycle
        if (u != v)
        {
            minWeight += weight;
            unionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}

int main()
{
    // Hardcoded graph parameters: n = 4 nodes, m = 5 edges
    // Each edge format: {u, v, weight}
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    cout << "Calculating Kruskal's MST Total Weight..." << endl;
    int totalMSTWeight = minimumSpanningTree(edges, n);

    cout << "Total Weight of Minimum Spanning Tree: " << totalMSTWeight << endl;

    return 0;
}