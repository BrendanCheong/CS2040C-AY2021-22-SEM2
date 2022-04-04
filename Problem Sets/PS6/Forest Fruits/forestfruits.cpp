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
#define INF 3e9
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

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll V, E, C, K, M; cin >> V >> E >> C >> K >> M;
    if (K > C && M > C) { // if K > C and M > C then its not possible, too many days and the growth rate is too long
        cout << -1 << '\n';
        return 0;
    }
    const ll source = 0;
    vector<vpll> AL(V, vpll());
    vll dist(V, INF);
    vll clearings;
    dist[source] = 0; // source node is 0 since cottage clearing is at 1 - 1 = 0 for zero-indexing
    for (size_t i = 0; i < E; i++) {
        ll u, v, w; cin >> u >> v >> w;
        AL[u - 1].emplace_back(v - 1, w);
        AL[v - 1].emplace_back(u - 1, w);
    }
    for (size_t i = 0; i < C; i++) {
        ll fruit; cin >> fruit;
        clearings.push_back(fruit - 1);
    }

    // (Modified) Dijkstra's algorithm
    std::priority_queue<pll, vpll, greater<pll>> pq; pq.push({ 0, source });

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        auto [d, u] = pq.top(); pq.pop();            // shortest unvisited u
        if (d > dist[u]) continue;                   // a very important check
        for (auto& [v, w] : AL[u]) {                 // all edges from u
            if (dist[u] + w >= dist[v]) continue;        // not improving, skip
            dist[v] = dist[u] + w;                       // relax operation, find the shortest path
            pq.push({ dist[v], v });                     // enqueue better pair
        }
    }

    vll possible_sites;
    for (auto& s : clearings) {
        if (dist[s] != INF)
            possible_sites.push_back(dist[s]);
    }
    sort(possible_sites.begin(), possible_sites.end()); // O(C log C)

    C = possible_sites.size();

    // 2 fruit trees and only 10 days (M > C) where there are a lot of days meaning we need a lot of fruits (big C), 
    // if the growth rate K is too large, where K > C, meaning that it takes too long to grow the trees back
    // then its impossible, -1
    // if the growth rate K is small, C >= K, meaning that trees grow back faster than the fruit sites, then its possible
    // if K == C, I must visit the Kth tree no matter what
    // if K < C, I visit the min(Kth, Cth) shortest distance tree
    if (M > C && K <= C) {
        cout << possible_sites[min(K, C) - 1] * 2 << '\n'; // account for zero indexing
        return 0;
    }
    else if (M > C && C < K) {
        cout << -1 << '\n';
        return 0;
    }

    // when 10 trees and 2 days or M <= C, I must look at my K growth rate for the answer compared to M
    // this scenario is always possible, since there are enough trees to go around and M is small enough
    // if the growth rate is too high, then I must venture out for more trees than K
    // if growth rate is small, just look for the smallest distance Kth tree
    // ie: if K == M, then I must take either Kth or Mth tree
    // if K < M, then take Kth tree
    // if K > M, then take Mth tree
    // so I must take the shortest path

    if (M <= C && K >= M) {
        cout << possible_sites[M - 1] * 2 << '\n';
        return 0;
    }
    else if (M <= C && K < M) {
        cout << possible_sites[K - 1] * 2 << '\n';
        return 0;
    }

    return 0;
}
