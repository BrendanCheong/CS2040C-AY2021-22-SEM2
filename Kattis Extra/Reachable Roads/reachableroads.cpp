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
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

template <class T>
class UnionFind {                                         // OOP style
private:
    vector<T> p, rank, setSize;                           // vll p is the key part
    T numSets;
public:
    UnionFind(T N) {
        p.assign(N, 0); for (size_t i = 0; i < N; ++i) p[i] = i; //? initially, parent of myself is myself, so p[i] = i
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    T findSet(T i) {
        return (p[i] == i)            //? if we have found the root, output the root, else continue to flatten tree until we have found root
            ? i
            : (p[i] = findSet(p[i])); // !flattens the tree so future reads are O(1) time instead O(log N)
    }
    bool isSameSet(T i, T j) {
        return findSet(i) == findSet(j);
    }

    ll numDisjointSets() {
        return numSets;
    }      // optional
    ll sizeOfSet(T i) {
        return setSize[findSet(i)];
    } // optional

    void unionSet(T i, T j) {
        if (isSameSet(i, j))
            return;               // i and j are in same set
        T x = findSet(i);
        T y = findSet(j);         // find both rep items
        if (rank[x] > rank[y])
            swap(x, y);           //? keep x 'shorter' than y, x is always shorter tree compared to y
        p[x] = y;                 //! set x under y, this combines two big subtrees into one tree
        if (rank[x] == rank[y])
            ++rank[y];            //? optional speedup, if the rank is actually the same, create a tree is that is one height taller, augmenting DS
        setSize[y] += setSize[x]; // !combine set sizes at y, this is for updating the size of the set, we only update the root of the tree, the subtree ignore
        --numSets;                // a union reduces numSets
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin >> n;
    while (n--) {
        ll m, r; cin >> m >> r;
        UnionFind<ll> UF(m);
        while (r--) {
            ll a, b; cin >> a >> b;
            UF.unionSet(a, b);
        }

        cout << UF.numDisjointSets() - 1 << '\n';
    }

    return 0;
}
