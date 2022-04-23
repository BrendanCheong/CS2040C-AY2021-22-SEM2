/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min
ll cnt = 0;

// print out vector
void printVector(vll& v) {
    ll N = v.size();
    cout << '[';
    if (!N) cout << ']';
    for (size_t i = 0; i < N; i++) {
        cout << v[i];
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

// print a vector of vectors
void printVectorOfVectors(vector<vll>& v) {
    ll N = v.size();
    for (size_t i = 0; i < N; i++) {
        cout << "index: " << i << ' ';
        printVector(v[i]);
    }
    cout << '\n';
}

void process(ll& d, vector<vector<pll>>& AL, vll& parent) {
    for (auto [v, w] : AL[d]) {
        if (v == parent[d]) {
            cnt += w;
            break;
        }
    }
}


int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll V, E; cin >> V >> E;
    vector<vector<pll>> AL(V, vector<pll>());

    for (size_t i = 0; i < E; i++) {
        ll u, v, w; cin >> u >> v >> w;
        --u; --v;
        AL[u].push_back({ v, w });
        AL[v].push_back({ u, w });
    }

    ll source = 0;
    vll dist(V, INF); dist[source] = 0;
    vll path(V, -1);

    // ?Original Dijkstra's algorithm

    set<pll> pq;                                    // balanced BST version
    for (int u = 0; u < V; ++u)                    // dist[u] = INF
        pq.insert({ dist[u], u });                     // but dist[s] = 0
      // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        auto [d, u] = *pq.begin();                   // shortest unvisited u
        pq.erase(pq.begin());
        if (d > dist[u]) continue;                   // a very important check to find shortest
        for (auto& [v, w] : AL[u]) {                 // all edges from u
            if (dist[u] + w >= dist[v]) continue;        // not improving, skip
            pq.erase(pq.find({ dist[v], v }));           // erase old pair
            dist[v] = dist[u] + w;                       // relax operation
            path[v] = u;                               // update prev[v] for path reconstruction
            pq.insert({ dist[v], v });                   // enqueue better pair
        }
    }

    // printVector(dist);
    // printVector(path);
    // ll d = V - 1;
    // while (path[d] != 0) {
    //     process(d, AL, path);
    //     d = path[d];
    // }
    // process(d, AL, path);
    // cout << cnt << '\n';
    cout << dist[V - 1] << '\n';

    return 0;
}
