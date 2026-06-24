// Implementation of Adjacency List using unordered_map and list

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void AddEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
            adj[v].push_back(u);
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
                cout << j << ",";
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter number of edges" << endl;
    cin >> m;

    Graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.AddEdge(u, v, 0);
    }

    // Demo input
    // 5
    // 6
    // 0 1
    // 1 2
    // 2 3
    // 3 1
    // 3 4
    // 0 4

    g.printAdjList();

    return 0;
}