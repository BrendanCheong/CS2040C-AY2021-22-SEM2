// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
using vll = vector<ll>;
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    T numDisjointSets() {
        return numSets;
    }      // optional
    T sizeOfSet(T i) {
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

int main() {
    printf("Assume that there are 5 disjoint sets initially\n");
    UnionFind<ll> UF(5); // create 5 disjoint sets
    cout << UF.numDisjointSets() << endl; // 5
    UF.unionSet(0, 1);
    cout << UF.numDisjointSets() << endl; // 4
    UF.unionSet(2, 3);
    cout << UF.numDisjointSets() << endl; // 3
    UF.unionSet(4, 3);
    cout << UF.numDisjointSets() << endl; // 2
    printf("isSameSet(0, 3) = %d\n", UF.isSameSet(0, 3)); // will return 0 (false)
    printf("isSameSet(4, 3) = %d\n", UF.isSameSet(4, 3)); // will return 1 (true)
    printf("isSameSet(2, 4) = %d\n", UF.isSameSet(2, 4)); // will return 1 (true)
    for (int i = 0; i < 5; i++) // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}
        printf("findSet(%d) = %lld, sizeOfSet(%d) = %lld\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    UF.unionSet(0, 3);
    cout << UF.numDisjointSets() << endl; // 1
    for (int i = 0; i < 5; i++) // findSet will return 3 for {0, 1, 2, 3, 4}
        printf("findSet(%d) = %lld, sizeOfSet(%d) = %lld\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
    return 0;
}