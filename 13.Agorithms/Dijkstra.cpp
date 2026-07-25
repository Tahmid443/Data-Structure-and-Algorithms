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
        graph[v].push_back({u, w}); // Remove for directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> distance(vertices, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (currentDistance > distance[currentVertex])
            continue;

        for (auto edge : graph[currentVertex])
        {
            int neighbor = edge.first;
            int weight = edge.second;

            if (distance[currentVertex] + weight < distance[neighbor])
            {
                distance[neighbor] = distance[currentVertex] + weight;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";

    for (int i = 0; i < vertices; i++)
    {
        cout << "Vertex " << i << " : ";

        if (distance[i] == INT_MAX)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }

    return 0;
}