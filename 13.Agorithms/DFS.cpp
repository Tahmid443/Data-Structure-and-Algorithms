#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor, graph, visited);
        }
    }
}

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(vertices);
    vector<bool> visited(vertices, false);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // Remove this line for directed graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    DFS(start, graph, visited);

    cout << endl;

    return 0;
}