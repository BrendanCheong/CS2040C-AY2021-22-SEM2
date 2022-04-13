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
typedef tuple<ll, ll, ll> tlll;
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

class UnionFind {                                // OOP style
private:
    vll p, rank, setSize;                           // vi p is the key part
    ll numSets;
public:
    UnionFind(ll N) {
        p.assign(N, 0); for (ll i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }
    ll findSet(ll i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }
    void unionSet(ll i, ll j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        ll x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }
    ll numDisjointSets() { return numSets; }
    ll sizeOfSet(ll i) { return setSize[findSet(i)]; }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m; cin >> n >> m;
    vll MST(n);
    vector<tlll> EL(m);
    UnionFind UF(n);

    for (size_t i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        tlll edge = { w, u, v };
        EL[i] = edge;
    }
    sort(EL.begin(), EL.end());

    ll num_taken = 0;               // no edge has been taken
    ll max_edge = -1;
    // note: the runtime cost of UFDS is very light
    for (ll i = 0; i < m; ++i) {                  // up to O(E)
        auto [w, u, v] = EL[i];                      // C++17 style
        if (UF.isSameSet(u, v)) continue;            // already in the same CC
        max_edge = max(w, max_edge);
        UF.unionSet(u, v);                           // link them
        ++num_taken;                                 // 1 more edge is taken
        if (num_taken == n - 1) break;                 // optimization
    }

    // my MST must connect to all the cities.
    // If the MST does not connect to all cities (maybe cities are not accessible)
    // then its impossible
    // we can check connectivity by looking at the number of edges in our MST
    // that must be equal to V - 1
    // if it is not equal to V - 1, then it is impossible
    // this for edge case where the whole graph is not 100% connected
    if (num_taken != n - 1) {
        cout << "IMPOSSIBLE" << '\n';
    }
    else { // max_edge, as we want AS MUCH battery as possible for our car
        cout << max_edge << '\n';
    }

    return 0;
}
