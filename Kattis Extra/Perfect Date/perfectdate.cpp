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
typedef vector<pll> vpll;
#define INF 0x3f3f3f3f
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

// print out vector
void printVector(vpll& v) {
    ll N = v.size();
    cout << '[';
    if (!N) cout << ']';
    for (size_t i = 0; i < N; i++) {
        cout << "<" << v[i].first << ", " << v[i].second << ">";
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

// print a vector of vectors
void printVectorOfVectors(vector<vpll>& v) {
    ll N = v.size();
    for (size_t i = 0; i < N; i++) {
        cout << "index: " << i << ' ';
        printVector(v[i]);
    }
    cout << '\n';
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll V; cin >> V;
    ll E = V - 1;
    vector<vpll> AL(V, vpll());
    vector<vll> tree(V, vll());
    for (size_t i = 0; i < E; i++) {
        ll u, v, w; cin >> u >> v >> w;
        --u; --v;
        AL[u].push_back({ v, w });
        AL[v].push_back({ u, w });
    }

    // need to do bfs from source node of test
    queue<ll> qu; qu.push(4);
    vpll dist(V, { INF, INF }); // <sum, weight>
    vector<bool> visited(V, false);
    dist[3] = { 0, 0 };
    while (!qu.empty()) {
        ll u = qu.front(); qu.pop();
        printf("visit %llu, ", u);
        for (auto& [v, w] : AL[u]) {
            auto [sum, weight] = dist[v];
            // sum > dist[u].first
            if (!visited[v]) {
                dist[v] = { pow(dist[u].first + w, 3), dist[u].second + w };
                visited[v] = true;
                qu.push(v);
            }
        }
    }

    // print out the distances
    ll ans = 0;
    for (auto& [k, v] : dist)
        ans += k;
    cout << ans * 2 << '\n';

    // print the AL
    for (size_t i = 0; i < V; i++) {
        cout << "index: " << i << ' ';
        printVector(AL[i]);
    }

    /**
     * Pseudo Code:
     * Given a tree, do V * DFS/BFS on the tree. Since its a tree, BFS is O(V-1) or O(V)
     * Thus, this creates a V^2 matrix of distances.
     * Next, find the ROW on this matrix that has the LOWEST SUM. Do this in O(V) time let equal to min(k)
     * Output ans as min(k) * 2 since we can go back and forth
    */

    return 0;
}
