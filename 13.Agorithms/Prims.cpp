#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<pii>> graph(vertices);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<bool> inMST(vertices, false);

    // {weight, vertex}
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int start = 0;
    pq.push({0, start});

    int totalCost = 0;

    cout << "\nEdges in the Minimum Spanning Tree:\n";

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;
        totalCost += weight;

        cout << "Vertex " << u << " added with edge weight " << weight << endl;

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (!inMST[v])
            {
                pq.push({w, v});
            }
        }
    }

    cout << "\nTotal Cost of MST = " << totalCost << endl;

    return 0;
}