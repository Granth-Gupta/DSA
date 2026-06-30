// Kruskal's Algorithm - CN

// TC - O(E logE) or O(E logV)
// SC - O(E)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator function to sort edges based on their weight (index 2)
bool cmp(vector<int> &a, vector<int> &b)
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

// Finds the representative root of a node with path compression
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

// Unites two sets based on their rank
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

// Kruskal's algorithm to calculate the weight of the Minimum Spanning Tree
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    // 1. Sort edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    // 2. Iterate through sorted edges and combine components
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        // If they belong to different components, add the edge to MST
        if (u != v)
        {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}

int main()
{
    // Number of vertices in the graph (0-indexed: 0, 1, 2, 3)
    int n = 4;

    // Edges representation: {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    int mstWeight = minimumSpanningTree(edges, n);

    cout << "The weight of the Minimum Spanning Tree is: " << mstWeight << endl;

    return 0;
}