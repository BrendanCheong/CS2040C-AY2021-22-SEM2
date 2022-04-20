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
typedef tuple<ll, ll, ll> lll;
#define INF 0x3f3f3f3f
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

// print out vector
void printVector(vector<pll>& v) {
    ll N = v.size();
    cout << '[';
    if (!N) cout << ']';
    for (size_t i = 0; i < N; i++) {
        auto& [k, c] = v[i];
        cout << "<" << k << ", " << c << ">";
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

// print a vector of vectors
void printVectorOfVectors(vector<vector<pll>>& v) {
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
    ll n; cin >> n;
    vector<pll> nodes;
    // I must reduce the size of edges for my complete graph 
    // but how many edges are there in an MST of a guaranteed complete graph?
    // Ans: the number of edges in an MST = V - 1
    // what about complete graphs?
    ll total_edges = (n * (n - 1)) / 2;
    ll reduced_edges = n - 1; // is my limit ceil(log_2(total_edges))?
    for (size_t i = 0; i < n; i++) {
        ll d; cin >> d;
        nodes.push_back({ d, i });
    }
    // by sorting, we only form the first lowest edges for the complete graph
    // perhaps you could implement partial sorting here? 
    partial_sort(nodes.begin(), nodes.begin() + reduced_edges, nodes.end()); // O(K log V) time

    // form the edges list
    vector<lll> EL;
    ll breaker = 0;
    // only iterates in O(V - 1) time, max is 199999
    for (size_t i = 0; i < nodes.size(); i++) {
        for (size_t j = 0; j < nodes.size(); j++) {
            if (i == j) continue;
            if (breaker == reduced_edges) break;
            auto [first_weight, idx1] = nodes[i];
            auto [second_weight, idx2] = nodes[j];
            EL.push_back({ first_weight + second_weight, idx1, idx2 });
            breaker++;
        }
        if (breaker == reduced_edges) break;
    }

    // print out EL
    // cout << "EL: ";
    // for (auto& [w, i, j] : EL) {
    //     cout << "<" << w << ", " << i << ", " << j << ">";
    // }

    ll mst_cost = 0, num_taken = 0;               // no edge has been taken
    UnionFind UF(n);                               // all V are disjoint sets
    // note: the runtime cost of UFDS is very light
    for (ll i = 0; i < EL.size(); ++i) {             // up to O(log (E)) in this case
        auto [w, u, v] = EL[i];                      // C++17 style
        if (UF.isSameSet(u, v)) continue;            // already in the same CC
        mst_cost += w;                               // add w of this edge
        UF.unionSet(u, v);                           // link them in O(ackerman(N))
        ++num_taken;                                 // 1 more edge is taken
        if (num_taken == n - 1) break;                 // optimization
    }

    cout << mst_cost << endl;
    // time complexity: O(V - 1) to proccess nodes, 
    // O(K log V) where K = reduced edges size
    // O(log E) to process everything else for Kruskal's

    // printVector(nodes);

    return 0;
}