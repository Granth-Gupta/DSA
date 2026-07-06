// Kosaraju's Algorithm is a two-pass algorithm used to find strongly connected components (SCCs) in a directed graph.
// The algorithm works as follows:
// 1. Perform a depth-first search (DFS) on the original graph and push the vertices onto a stack in the order of their finishing times.
// 2. Create a transposed graph by reversing the direction of all edges.
// 3. Perform DFS on the transposed graph, starting from the vertices in the order defined by the stack. Each DFS call will give you one strongly connected component.
// 4. Repeat the process until all vertices have been processed. The output will be the strongly connected components of the graph.

// The time complexity of Kosaraju's algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph. This is because we perform two depth-first searches, each taking O(V + E) time. The space complexity is also O(V + E) due to the storage of the graph and the stack used for processing vertices.
// The algorithm is efficient and works well for large graphs, making it a popular choice for finding strongly connected components in directed graphs.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

// TC: O(V + E)
// SC: O(V)

// Helper DFS function to find topological sort-like ordering
void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, st, adj);
        }
    }
    // Push the node to the stack when backtracking finishes
    st.push(node);
}

// Helper DFS function to traverse the transposed graph
void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            revDfs(nbr, vis, adj);
        }
    }
}

// Main function to find the number of strongly connected components
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{

    // Step 1: Create the adjacency list
    unordered_map<int, list<int>> adj;
    for (size_t i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int val = edges[i][1]; // labeled as 'v' in screenshot, renamed to 'val' to avoid collision with vertex count 'v'
        adj[u].push_back(val);
    }

    // Step 2: Perform DFS and populate the stack (Topological sort ordering)
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    // Step 3: Create the transpose (reversed) graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = false; // Resetting visited map for step 4
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // Step 4: Process vertices in the order defined by the stack
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!vis[top])
        {
            count++;
            revDfs(top, vis, transpose);
        }
    }

    return count;
}