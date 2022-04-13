// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> iii;

// The main function that finds shortest
// distances from src to all other vertices
// using Bellman-Ford algorithm. The function
// also detects negative weight cycle
// The row graph[i] represents i-th edge with
// three values u, v and w.
void BellmanFord(vector<iii>& graph, int V, int E, int src) {
    // Initialize distance of all vertices as infinite.
    int dis[V];
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;

    // initialize distance of source as 0
    dis[src] = 0;

    // Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other
    // vertex can have at-most |V| - 1 edges
    for (int i = 0; i < V - 1; i++) {

        for (int j = 0; j < E; j++) {
            if (dis[get<0>(graph[j])] != INT_MAX && dis[get<0>(graph[j])] + get<2>(graph[j]) < dis[get<1>(graph[j])])
                dis[get<1>(graph[j])] = dis[get<0>(graph[j])] + get<2>(graph[j]);
        }
    }

    // check for negative-weight cycles.
    // The above step guarantees shortest
    // distances if graph doesn't contain
    // negative weight cycle.  If we get a
    // shorter path, then there is a cycle.
    for (int i = 0; i < E; i++) {
        int x = get<0>(graph[i]);
        int y = get<1>(graph[i]);
        int weight = get<2>(graph[i]);
        if (dis[x] != INT_MAX &&
            dis[x] + weight < dis[y])
            cout << "Graph contains negative"
            " weight cycle"
            << endl;
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
}

// Driver program to test above functions
int main()
{

    int V, E; cin >> V >> E;
    // V: Number of vertices in graph
    // E: Number of edges in graph

    // Every edge has three values (u, v, w) where
    // the edge is from vertex u to v. And weight
    // of the edge is w.
    vector<iii> graph(E);
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[i] = { u, v, w };
    }

    BellmanFord(graph, V, E, 3);
    return 0;
}