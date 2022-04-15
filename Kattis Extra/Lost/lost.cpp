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
typedef tuple<ll, ll, ll, ll> llll;
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
    vector<vector<pll>> AL(n + 1);
    vector<llll> EL;
    unordered_map<string, ll> languages; languages.reserve(n + 1);
    languages["English"] = 0;
    for (size_t i = 1; i < n + 1; i++) { // O(V)
        string s; cin >> s;
        languages[s] = i;
    }

    for (size_t i = 0; i < m; i++) { // O(E)
        string l1, l2; cin >> l1 >> l2;
        ll w; cin >> w;
        AL[languages[l1]].push_back({ languages[l2], w });
        // AL[languages[l2]].push_back({ languages[l1], w });
    }

    // since this qns uses lowest number of hops, followed by lowest weight of edge, its a modified BFS algo
    // in order to find the number of layers for each edge
    queue<ll> qu; qu.push(0);
    vll dist(n + 1, INF); dist[0] = 0;
    ll layer = -1;
    while (qu.size() > 0) { // O(V+E)
        ll u = qu.front(); qu.pop();
        layer = dist[u];
        for (auto& [v, w] : AL[u]) {
            // printf("vertex %llu is visiting vertex %llu of weight %llu, in layer %llu\n", u, v, w, layer + 1);
            EL.push_back({ layer + 1, w, u, v });
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                // cout << "hops from " << u << " to " << v << ": " << dist[v] << '\n';
                qu.push(v);
            }
        }
    }
    // comparator for EL
    // pick the smallest first index first
    // if identical, pick the smallest second index

    auto comp = [](llll& e1, llll& e2) {
        if (get<0>(e1) == get<0>(e2)) {
            return get<1>(e1) < get<1>(e2);
        }
        return get<0>(e1) < get<0>(e2);
    };

    sort(EL.begin(), EL.end(), comp); // O(E log E)

    // print EL
    // for (auto& e : EL)
    //     cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << " " << get<3>(e) << '\n';
    // printVector(dist);

    ll mst_cost = 0, num_taken = 0;               // no edge has been taken
    UnionFind UF(n + 1);                               // all V are disjoint sets
    // note: the runtime cost of UFDS is very light
    for (ll i = 0; i < m; ++i) {                  // up to O(E)
        auto [l, w, u, v] = EL[i];                      // C++17 style
        if (UF.isSameSet(u, v)) continue;            // already in the same CC
        mst_cost += w;                               // add w of this edge
        UF.unionSet(u, v);                           // link them
        ++num_taken;                                 // 1 more edge is taken
        if (num_taken == n) break;                 // optimization
    }
    // note: the number of disjoint sets must eventually be 1 for a valid MST
    // total time: O(E log V)
    if (num_taken != n)
        cout << "Impossible" << '\n';
    else
        cout << mst_cost << '\n';

    // total Time complexity: O(E) + O(V) + O(V+E) + O(E log E) + O(E log V) = O(E log E) in this case as E > V

    return 0;
}

