#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

    if (u != v) // Only union if they are in different sets
    {
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
}

int main()
{
    // Number of elements/nodes (0, 1, 2, 3)
    int n = 4;

    // Allocate memory for parent and rank arrays
    vector<int> parent(n);
    vector<int> rank(n);

    // Initialize DSU arrays
    makeSet(parent, rank, n);

    cout << "--- Initial State ---" << endl;
    cout << "Parent of 1: " << findParent(parent, 1) << endl;
    cout << "Parent of 3: " << findParent(parent, 3) << endl;

    // Perform some Union operations
    cout << "\n--- Performing Unions ---" << endl;
    cout << "Union(1, 3)" << endl;
    unionSet(1, 3, parent, rank);

    cout << "Union(0, 2)" << endl;
    unionSet(0, 2, parent, rank);

    // Check representatives after unions
    cout << "\n--- State After Unions ---" << endl;
    cout << "Parent of 1: " << findParent(parent, 1) << endl;
    cout << "Parent of 3: " << findParent(parent, 3) << endl;

    // Check if two elements belong to the same set
    if (findParent(parent, 1) == findParent(parent, 3))
    {
        cout << "Nodes 1 and 3 are in the SAME set." << endl;
    }
    else
    {
        cout << "Nodes 1 and 3 are in DIFFERENT sets." << endl;
    }

    if (findParent(parent, 1) == findParent(parent, 2))
    {
        cout << "Nodes 1 and 2 are in the SAME set." << endl;
    }
    else
    {
        cout << "Nodes 1 and 2 are in DIFFERENT sets." << endl;
    }

    return 0;
}