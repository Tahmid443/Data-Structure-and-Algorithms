#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, weight;
};

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node], parent);
}

// Union function
void unionSets(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u != v)
    {
        if (rank[u] < rank[v])
            swap(u, v);

        parent[v] = u;

        if (rank[u] == rank[v])
            rank[u]++;
    }
}

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<Edge> graph(edges);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> graph[i].u >> graph[i].v >> graph[i].weight;
    }

    // Sort edges by weight
    sort(graph.begin(), graph.end(), [](Edge a, Edge b)
    {
        return a.weight < b.weight;
    });

    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    int totalCost = 0;

    cout << "\nEdges in the Minimum Spanning Tree:\n";

    for (Edge edge : graph)
    {
        if (findParent(edge.u, parent) != findParent(edge.v, parent))
        {
            cout << edge.u << " - " << edge.v
                 << " : " << edge.weight << endl;

            totalCost += edge.weight;

            unionSets(edge.u, edge.v, parent, rank);
        }
    }

    cout << "\nTotal Cost of MST = " << totalCost << endl;

    return 0;
}