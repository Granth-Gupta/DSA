// Dijkstra's Shortest Path - CN

// TC -> O(E logV)
// SC -> O(E + V)

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // creation of distance array with infinite value initially
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;

    // creation of set on basis (distance, node)
    set<pair<int, int>> st;

    // initialse distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;

        // erase top record
        st.erase(st.begin());

        // traverse to neighbours
        for (auto neighbour : adj[topNode])
        {
            if (neighbour.second + nodeDist < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // if record found then erase it
                if (record != st.end())
                    st.erase(record);

                dist[neighbour.first] = neighbour.second + nodeDist;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main()
{
    int v = 4;
    int e = 5;
    int s = 0;

    vector<vector<int>> egde = {{0, 1, 5}, {0, 2, 8}, {1, 2, 9}, {1, 3, 2}, {2, 3, 6}};
    vector<int> ans = dijkstra(egde, v, e, s);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}