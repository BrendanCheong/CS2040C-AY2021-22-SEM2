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

void multisourceBFS(vector<vll>& AL, queue<ll>& qu, vll& dist, vector<bool>& visited, vll& source) {
    while (!qu.empty()) {
        ll k = qu.front();
        qu.pop();

        for (auto& i : AL[k]) {
            if (!visited[i]) {
                // push the adjacent unvisited vertices
                // with distance from current source = this
                // vertex's distance + 1
                qu.push(i);
                dist[i] = dist[k] + 1;
                // days[dist[k] + 1].push_back(i); // optional, updates the number of days corresponding to distance
                visited[i] = true;
            }
        }
    }
}

void nearestToMaxNode(vector<vll>& AL, vll& source, vll& dist, vector<bool>& visited, ll& N) {
    ll n = source.size();
    queue<ll> qu;

    for (size_t i = 0; i < n; i++) {
        qu.push(source[i]);
        visited[source[i]] = true;
    }

    multisourceBFS(AL, qu, dist, visited, source);

    // printVector(dist);
    /**
     * Since Alice can choose the red paths, and since all thr weights are 1 since its an unweighted
     * double sided edge graph, Alice will ALWAYS make the shortest path ALTERNATING COLOURS.
     * Since its alternating colours, the answer is always dist[desired node] - 1.
    */
    cout << dist[N - 1] - 1 << '\n';

}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m; cin >> n >> m;
    vector<vll> AL(n, vll());
    vll dist(n, 0); // make sure its NOT INF, we are finding hops, not SSSP here with BFS
    vector<bool> visited(n, false);
    while (m--) { // account for zero indexing
        ll u, v; cin >> u >> v;
        AL[u - 1].push_back(v - 1);
        AL[v - 1].push_back(u - 1);
    }

    // printVectorOfVectors(AL);

    // do a multisource bfs
    const ll source = 1 - 1; // account for zero indexing
    vll source_arr; source_arr.push_back(source);

    nearestToMaxNode(AL, source_arr, dist, visited, n);

    return 0;
}
