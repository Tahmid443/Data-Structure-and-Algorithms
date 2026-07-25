#include <bits/stdc++.h>
using namespace std;

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

    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;

    return 0;
}