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
        AL[languages[l2]].push_back({ languages[l1], w });
    }

    // since this qns uses lowest number of hops, followed by lowest weight of edge, its a modified BFS algo
    // in order to find the number of layers for each edge
    queue<ll> qu; qu.push(0);
    vector<pll> dist(n + 1, { INF, INF });
    dist[0] = { 0, 0 };
    while (qu.size() > 0) { // O(V+E)
        ll u = qu.front(); qu.pop();
        auto [layer, distance] = dist[u]; // hold 2 kinds of distance, hops from the source and actual edge weight
        for (auto& p : AL[u]) {
            auto& [v, w] = p;
            auto& [layer2, distance2] = dist[v];

            // If we can get to a node with less translations
            // we find the edge with the lowest amount of layers or hops from the source
            // each vertex has its weight
            // layer always starts of at 0
            // layer + 1 is like your BFS relaxation, dist[u] + 1
            if (layer + 1 < layer2) {
                dist[v] = { layer + 1, w }; // we update the current distance with <number of smallest hops, weight of u->v>
                qu.push(v);
            }
            // If we can get to a node with the same translations and less money
            // pick the least weighted incoming edge
            // for example, vertex "Swedish" has either (A to S as 5) or (F to S as 1)
            // we compare vertex u -> v weight vs previous weight of previous vertexes u2 -> v weight and pick the smallest one  
            else if (layer + 1 == layer2) {
                dist[v].second = min(w, distance2); // take the smallest weighted edge
            }
        }
    }

    // print dist vector
    ll ans = 0;
    for (auto& [k, v] : dist) {
        if (v == INF) {
            cout << "Impossible\n";
            return 0;
        }
        ans += v;
    }

    cout << ans << '\n';

    /**
     * Pseudo Code:
     * We will decide to use BFS in this case as we need to count the number of hops
     * Since we will use BFS, we can modify it such that when we relax the vertices, we can not only count the number of hops
     * But we can also make sure the vertice stores the SMALLEST WEIGHTED incoming edge to that vertex
     * Thus, our distance array stores index of vertex: <number of hops, smallest incoming edge weight>
     * We first detect if number of hops is < current number hops whe u -> v (starts off as 0 + 1 < INF)
     * If number of hops are the same, take the min of the weights of the incoming edges
     * thus the relaxation function is like this := distance[v] = { distance[u].first + 1 (first is the number of hops), min(distance[u].second, w) second is the weight }
     * Take away is that BFS can store additional information in each vertex, especially for incoming edges AND number of hops
    */

    return 0;
}

