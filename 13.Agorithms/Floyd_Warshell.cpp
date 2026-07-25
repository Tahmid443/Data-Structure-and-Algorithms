#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> dist(vertices, vector<int>(vertices, INF));

    // Distance from a vertex to itself is 0
    for (int i = 0; i < vertices; i++)
        dist[i][i] = 0;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = w;
        dist[v][u] = w;   // Remove this line for directed graph
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}