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
    deque<ll> q; q.push_front(source);

    while (!q.empty()) {
        ll v = q.front();
        q.pop_front();
        for (auto& [u, w] : AL[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w; //! IMPORTANT: I must relax the vertex first!!
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }

    cout << dist[V - 1] << '\n'; //! since we are only concerned about +1 bridges, num of bridges = dist to bridge

    return 0;
}
