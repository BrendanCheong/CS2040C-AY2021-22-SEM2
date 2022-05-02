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

template <class T>
class UnionFind {                                         // OOP style
private:
    vector<T> p, rank, setSize, characters;                           // vll p is the key part
    T numSets;
public:
    UnionFind(T N) {
        p.assign(N, 0); for (size_t i = 0; i < N; ++i) p[i] = i; //? initially, parent of myself is myself, so p[i] = i
        rank.assign(N, 0);                           // optional speedup
        characters.assign(N, 0);                     // optional speedup
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
        if (rank[x] > rank[y]) {
            characters[x] = min(characters[y], characters[x]);
            swap(x, y);           //? keep x 'shorter' than y, x is always shorter tree compared to y
        }
        p[x] = y;                 //! set x under y, this combines two big subtrees into one tree
        if (rank[x] == rank[y])
            ++rank[y];            //? optional speedup, if the rank is actually the same, create a tree is that is one height taller, augmenting DS
        setSize[y] += setSize[x]; // !combine set sizes at y, this is for updating the size of the set, we only update the root of the tree, the subtree ignore
        characters[y] = min(characters[y], characters[x]); // find smaller one
        --numSets;                // a union reduces numSets
    }

    void setCharacters(T i, T j) {
        characters[i] = j;
    }

    vector<T> getCharacters() {
        return characters;
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m; cin >> n >> m;
    unordered_map<string, ll> essay; essay.reserve(n);
    UnionFind<ll> UF(15);
    vector<string> sentence;
    for (size_t i = 0; i < n; i++) {
        string words; cin >> words;
        if (!essay.count(words)) {
            essay[words] = essay.size();
            sentence.push_back(words);
            UF.setCharacters(essay[words], words.size());
        }
    }

    while (m--) {
        string a, b; cin >> a >> b;
        vector<string> line = { a, b };
        for (auto& word : line) {
            if (!essay.count(word)) {
                essay[word] = essay.size();
                UF.setCharacters(essay[word], word.size());
            }
        }
        UF.unionSet(essay[a], essay[b]);
    }

    vector<ll> stuff = UF.getCharacters();
    ll ans = 0;
    for (auto& word : sentence) {
        ans += stuff[UF.findSet(essay[word])];
    }
    cout << ans << '\n';

    return 0;
}