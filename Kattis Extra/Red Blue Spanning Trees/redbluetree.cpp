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

class UnionFind {                                // OOP style
private:
    vll p, rank, setSize;                           // vi p is the key part
    ll numSets;
public:
    UnionFind(ll N) {
        p.assign(N, -1);
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }
    ll findSet(ll i) {
        return (p[i] == -1) ? i : (p[i] = findSet(p[i]));
    }
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
    vll getParentVectors() { return p; }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, k; cin >> n >> m >> k;
    UnionFind Blue(n);
    UnionFind Red(n);

    for (size_t i = 0; i < m; i++) {
        char c; cin >> c;
        ll f, t; cin >> f >> t;
        --f; --t;

        switch (c) {
        case('B'):
            Blue.unionSet(f, t);
            break;
        case('R'):
            Red.unionSet(f, t);
            break;
        }
    }

    ll blue_needed = 0;
    for (ll i = 0; i < n; i++) {
        if (Red.getParentVectors()[i] == -1) {
            blue_needed++;
        }
    }
    blue_needed--;

    ll blue_avail = 0;
    for (ll i = 0; i < n; i++) {
        if (Blue.getParentVectors()[i] != -1) {
            blue_avail++;
        }
    }

    (blue_avail < k || blue_avail < blue_needed || blue_needed > k)
        ? cout << 0 << '\n'
        : cout << 1 << '\n';

    return 0;
}
