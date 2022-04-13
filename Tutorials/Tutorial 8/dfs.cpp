#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but shortcuts are useful in competitive programming

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

vi p;                                            // addition:parent vector

void printPath(int u) {                          // extract info from vi p, p is the parent vector
    if (p[u] == -1) { printf("%d", u); return; }
    printPath(p[u]);                               // output format: s -> ... -> t
    printf(" %d", u);
}

int main() {
    /*
    Graph in Figure 4.3, format: list of unweighted edges
    This example shows another form of reading graph input
    13 16
    0 1    1 2    2  3   0  4   1  5   2  6    3  7   5  6
    4 8    8 9    5 10   6 11   7 12   9 10   10 11  11 12
    */

    freopen("bfs_in.txt", "r", stdin);
    // freopen("dfs_cc_in.txt", "r", stdin);

    int V, E; scanf("%d %d", &V, &E);
    vector<vii> AL(V, vii());
    for (int i = 0; i < E; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        AL[a].emplace_back(b, 0);
        AL[b].emplace_back(a, 0);
    }

    // int V; scanf("%d", &V);
    // vector<vii> AL(V, vii());
    // AL.assign(V, vii());
    // for (int u = 0; u < V; ++u) {
    //     int k; scanf("%d", &k);
    //     while (k--) {
    //         int v, w; scanf("%d %d", &v, &w);
    //         AL[u].emplace_back(v, w);
    //     }
    // }

    // as an example, we start from this source, see Figure 4.3
    int s = 5;
    cout << "=============== DFS ITERATIVE =================" << endl;

    vi dist(V, INF); dist[s] = 0;                  // INF = 1e9 here
    stack<int> stack; stack.push(s);                       // start BFS from s
    p.assign(V, -1);                               // p is global

    bool isBipartite = true;                       // additional feature

    while (!stack.empty()) {
        int u = stack.top(); stack.pop();
        // if (dist[u] != layer) printf("\nLayer %d: ", dist[u]);
        printf("visit %d \n", u);
        for (auto& [v, w] : AL[u]) {                 // C++17 style, w ignored
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;                     // dist[v] != INF now, we have visited the vertex
                p[v] = u;                                // parent of v is u
                stack.push(v);                               // for next iteration
            }
            else if ((dist[v] % 2) == (dist[u] % 2))       // same parity
                isBipartite = false;
        }
    }

    printf("\nShortest path: ");
    printPath(7), printf("\n");
    printf("isBipartite? %d\n", isBipartite);

    return 0;
}