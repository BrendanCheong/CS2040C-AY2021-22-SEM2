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
    vector<T> p, rank, setSize, drawerSize;                           // vll p is the key part
    ll numSets;
public:
    UnionFind(T N) {
        p.assign(N, 0); for (size_t i = 0; i < N; ++i) p[i] = i; //? initially, parent of myself is myself, so p[i] = i
        rank.assign(N, 0);                           // optional speedup
        drawerSize.assign(N, 0);                     // optional speedup
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
        drawerSize[y] += drawerSize[x]; // combines sets
        --numSets;                // a union reduces numSets
    }

    /**
     * What this does is decide whether to add to my drawer given the pairs or discard it
     * When adding to a drawer, we increment the drawer's current size
     * this is separate from the union operation because we need to know the size of the drawer before we add to it
     * We union first then decide whether to increase the drawer's size
     * Another alternate solution is to break up the union by some deleteUnion operation instead of keeping a separate vector
     * But this is a little more complicated than it needs to be.
    */
    bool addToDrawer(T i) {
        T x = findSet(i); // find parent
        ++drawerSize[x];
        if (drawerSize[x] > setSize[x]) { // if my adding to my parent makes it bigger then the actual size, then theres no space
            --drawerSize[x];
            return false;
        }
        else {
            return true;
        }
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, l; cin >> n >> l;
    UnionFind<ll> UF(l + 1);
    while (n--) {
        ll A, B; cin >> A >> B;
        UF.unionSet(A, B);
        UF.addToDrawer(A)
            ? cout << "LADICA"
            : cout << "SMECE";
        cout << '\n';
    }
    return 0;
}