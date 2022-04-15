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
typedef vector<pll> vpll;
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

ll process(ll u, vector<bool>& taken, vector<vll>& AL, ll& army_size,
    std::priority_queue<pll, vpll, greater<pll>>& pq, unordered_map<ll, ll>& weights) { // set u as taken and enqueue neighbors of u
    taken[u] = true;
    for (auto& v : AL[u]) // process all neighbours of u
        if (!taken[v])
            pq.push({ weights[v], v });                         // sort by non-dec weight
    return army_size + weights[u]; //!IMPORTANT: increment previous army size with what I can visit
}

void conquest(ll& V, vector<vll>& AL, unordered_map<ll, ll>& weights, vector<bool>& taken,
    std::priority_queue<pll, vpll, greater<pll>>& pq) {
    ll army_size = 0;

    // initially I want to find all neighbours of first vertex
    // and add them to the pq
    army_size = process(0, taken, AL, army_size, pq, weights);
    ll num_taken = 0; // counts number of edges processed


    //! Modified Prim's Algo, we continue to find smallest weight vertex ONLY if my army is bigger
    while (!pq.empty() && army_size > pq.top().first) {
        auto [w, v] = pq.top(); pq.pop();
        if (!taken[v]) {
            army_size = process(v, taken, AL, army_size, pq, weights);
            ++num_taken;                                 // 1 more edge is taken    
        }
        if (num_taken == V - 1) break;                  // all edges are taken, optimisation
    }
    cout << army_size << '\n';
    //!NOTE: by default, the army_size is initially weights[0], if I can't visit anything, the answer is NOT 0!
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll V, E; cin >> V >> E;
    vector<vll> AL(V, vll()); // store vertex: List[vertex]
    unordered_map<ll, ll> weights; // this will store the vertex and its weight, <v, w> vertex: weight
    weights.reserve(V + 1);
    vector<bool> taken(V, false);
    std::priority_queue<pll, vpll, greater<pll>> pq;

    // process AL
    for (size_t i = 0; i < E; i++) {
        ll u, v; cin >> u >> v;
        --u; --v; // for zero indexing
        AL[u].push_back(v);
        AL[v].push_back(u);
        // undirected edge, weightless for now...
    }

    // printVectorOfVectors(AL);

    for (size_t i = 0; i < V; i++) {
        ll w; cin >> w;
        weights[i] = w;
    }

    conquest(V, AL, weights, taken, pq);

    /**
     * ? The Pseudo code is as follows:
     * This is a modified Prim's Algorithm
     * 1. First create an Adj List, we can't use Kruskal because we need to go from vertex 1 to all neighbors
     * 2. Create a MIN HEAP, sort by ascending order. We want to greedily find the smallest weight thats less than current army size
     * 3. We want to process once to initialise the pq with vertex 1's neighbors
     * 4. At the same time when processing, we want to add army size with the weight of the vertex we visit
     * 5. So we start of by visiting vertex 1
     * 6. While the heap is not empty, we will greedily find the smallest weight vertex, and add it to the army size, starting from vertex 1's neighbors
     * 7. We end once we cannot visit any more neighbours as our army size is not big enough to continue adding
     * 8. Thus, Modified Prim's Algorithm finds the neighbours we can visit, where the MST is not the edge weight but vertex weight
     * 9. army size acts as a global variable
    */

    return 0;
}
